#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <TMatrixDSym.h>
#include <TMatrixDSymEigen.h>
#include <TVectorD.h>
#include <TF1.h>

using namespace std;

#define TOLERANCE 1e-6
#define MAX_ITER 1000
#define MIN 0.3
#define MAX 10000

// -----------------------------------------------------------------------------
// Define here all the parameters and covariance matrix extracted from the fit
// -----------------------------------------------------------------------------

double FitParam2024[5] = {0.00715155, -29.1616, 0.875561, 6.91718, -2.82801};
double covMatrix2024[5][5] = {
    {1.50116e-10, 3.13094e-12, -2.90955e-09, -6.56178e-09, 2.7389e-09},
    {3.13094e-12, 5.91383e-09, 1.05878e-10, -1.40831e-09, 3.86214e-11},
    {-2.90955e-09, 1.05878e-10, 5.84564e-08, 1.81817e-07, -5.18447e-08},
    {-6.56178e-09, -1.40831e-09, 1.81817e-07, 1.83453e-06, -8.52439e-08},
    {2.7389e-09, 3.86214e-11, -5.18447e-08, -8.52439e-08, 5.11685e-08}
};


// -----------------------------------------------------------------------------
// Initialization functions
// -----------------------------------------------------------------------------
struct BetaGammaMinResult {
    double bg_nominal;
    double bg_up;
    double bg_down;

    double params_nom[6];   // parameters used for bg_nominal
    double params_up[6];    // parameters used for bg_up
    double params_down[6];  // parameters used for bg_down
};

TMatrixDSym InitializeCovMatrix(double covMatrix[5][5]) {
    TMatrixDSym Cov = TMatrixDSym(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) Cov(i, j) = covMatrix[i][j];
    }

    return Cov;
}

double findMinimumX(const double *par) {
    TF1 f("f", AtlasFunction, MIN, MAX, 6);
    for (int i = 0; i < 6; i++) f.FixParameter(i, par[i]);

    // If the minimum is above zero, no physical solution
    // appen if Ih < min value = 2.95863 (corresponding to bg=6.98->if p<6.98*m no solution)
    if (f.Eval(f.GetMinimumX()) > 0) return -1;

    return f.GetMinimumX();
}


// -----------------------------------------------------------------------------
// Fit function
// -----------------------------------------------------------------------------
double AtlasFunction(double *x, double *par) {
  double bg = x[0];
  double dEdx = par[0];

  double p1 = par[1];
  double p2 = par[2];
  double p3 = par[3];
  double p4 = par[4];
  double p5 = par[5];
  

  double term1 = pow( ( sqrt(pow(bg,4) + 4*(bg)*(bg)) - (bg)*(bg) )/2 , p2/2);

  return p1 * term1 * log(1 + pow(p3 * bg, p4)) - p5 - dEdx;        
}


// -----------------------------------------------------------------------------
// Compute minimum including correlations using eigen-decomposition
// -----------------------------------------------------------------------------
BetaGammaMinResult findBetaGammaWithCovariance(double Ih, const double *FitParam, const TMatrixDSym &Cov) {
    // --- Nominal parameter vector --------------------------------------------
    double p_nom[6] = {Ih,
                       FitParam[0],
                       FitParam[1],
                       FitParam[2],
                       FitParam[3],
                       FitParam[4]};

    TVectorD p0(5);
    for (int i=0; i<5; i++) p0[i] = p_nom[i+1];

    // --- Diagonalize covariance matrix ---------------------------------------
    TMatrixDSymEigen eigen(Cov);                     // /!\ only FitParam in it !
    TVectorD  eigenVal = eigen.GetEigenValues();     // λ_k
    TMatrixD  eigenVec = eigen.GetEigenVectors();    // V_ik

    // --- Nominal minimum ------------------------------------------------------
    BetaGammaMinResult R;
    R.bg_nominal = findMinimumX(MIN, MAX, p_nom);

    double min_up  = R.bg_nominal;
    double min_down = R.bg_nominal;

    // --- Loop over each eigen-direction --------------------------------------
    for (int k=0; k<5; k++)
    {
        double sigma_k = sqrt( eigenVal[k] );

        // Build +/- delta parameter vectors
        TVectorD delta(5);
        for (int i=0; i<5; i++)
            delta[i] = eigenVec(i,k) * sigma_k;

        double p_up[6];
        double p_down[6];

        // dEdx stays the same (index 0)
        p_up[0]   = Ih;
        p_down[0] = Ih;

        // Apply p ± delta
        for (int i=0; i<5; i++) {
            p_up[i+1]   = p0[i] + delta[i];
            p_down[i+1] = p0[i] - delta[i];
        }

        // Compute minima for each variation
        double x_up   = findMinimumX(MIN, MAX, p_up);
        double x_down = findMinimumX(MIN, MAX, p_down);

        // Keep envelope: worst-case shifts
        if (x_up   > min_up)   min_up   = x_up;
        if (x_down < min_down) min_down = x_down;
    }

    // --- Final asymmetric uncertainties ---------------------------------------
    R.bg_up   = min_up;
    R.bg_down = min_down;

    for (int i = 0; i < 6; i++) {
        R.params_nom[i]  = p_nom[i];       // nominal
        R.params_up[i]   = p_up[i];        // upper
        R.params_down[i] = p_down[i];      // lower
    }

    return R;
}


// -----------------------------------------------------------------------------
// Find zero of the function using Bisection Method
// -----------------------------------------------------------------------------
double ZeroBisectionMethod(double a, double b, const double *params)
{
    TF1 *f = new TF1("f", AtlasFunction, a, b, 6);
    f->FixParameter(0, params[0]); // dEdx
    f->FixParameter(1, params[1]);
    f->FixParameter(2, params[2]);
    f->FixParameter(3, params[3]);
    f->FixParameter(4, params[4]);
    f->FixParameter(5, params[5]);

    double fa = f->Eval(a);
    double fb = f->Eval(b);

    if (fa * fb >= 0) return -1;

    int iter = 0;
    double c;

    while ((b - a) > TOLERANCE && iter < MAX_ITER) {
        c = (a + b) / 2;
        double fc = f->Eval(c);
        if (fc == 0.0)
            return c;
        else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        iter++;
    }

    return (a + b) / 2;
}


// -----------------------------------------------------------------------------
// Find zero of the function using Brent's Method
// https://people.math.sc.edu/Burkardt/cpp_src/brent/brent.html#:~:text=BRENT%2C%20a%20C%2B%2B%20library%20which,that%20the%20function%20is%20differentiable
// -----------------------------------------------------------------------------
double ZeroBrentMethod (double a, double b, double t, const double *params)
{
    double c;
    double d;
    double e;
    double fa;
    double fb;
    double fc;
    double m;
    double macheps;
    double p;
    double q;
    double r;
    double s;
    double sa;
    double sb;
    double tol;

    TF1 f("f", AtlasFunction, a, b, 6);
    for (int i = 0; i < 6; i++)
        f.FixParameter(i, params[i]);


    // Make local copies of A and B.
    sa = a;
    sb = b;
    fa = f->Eval(sa);
    fb = f->Eval(sb);

    c = sa;
    fc = fa;
    e = sb - sa;
    d = e;

    macheps = 2.220446049250313E-016;

    for ( ; ; )
    {
        if (fabs(fc) < fabs(fb))
        {
            sa = sb;
            sb = c;
            c = sa;
            fa = fb;
            fb = fc;
            fc = fa;
        }

        tol = 2.0*macheps*fabs(sb) + t;
        m = 0.5*(c - sb);

        if (fabs(m) <= tol || fb == 0.0)
        {
            break;
        }

        if (fabs(e) < tol || fabs(fa) <= fabs(fb))
        {
            e = m;
            d = e;
        }
        else
        {
            s = fb/fa;

            if ( sa == c )
            {
                p = 2.0*m*s;
                q = 1.0 - s;
            }
            else
            {
                q = fa/fc;
                r = fb/fc;
                p = s*(2.0*m*q*(q-r)-(sb-sa)*(r-1.0));
                q = (q-1.0)*(r-1.0)*(s-1.0);
            }

            if ( 0.0 < p ) q = - q;
            else p = - p;

            s = e;
            e = d;

            if (2.0*p < 3.0*m*q-fabs(tol*q) && p < fabs(0.5*s*q)) d = p/q;
            else
            {
                e = m;
                d = e;
            }
        }
        sa = sb;
        fa = fb;

        if (tol < fabs(d)) sb = sb + d;
        else if (0.0 < m) sb = sb + tol;
        else sb = sb - tol;

        fb = f->Eval(sb);

        if ((0.0<fb && 0.0<fc) || (fb<=0.0 && fc<=0.0))
        {
            c = sa;
            fc = fa;
            e = sb - sa;
            d = e;
        }
    }
    return sb;
}


// -----------------------------------------------------------------------------
// Main function to be called
// -----------------------------------------------------------------------------
double findMass(const double p, const double Ih, const std::string year, bool up, bool down)
{
    TMatrixDSym CovMatrix = TMatrixDSym(5);
    double *params = nullptr;
    if (year == "2024") {
        params = FitParam2024;
        CovMatrix = InitializeCovMatrix(covMatrix2024);
    }

    BetaGammaMinResult R = findBetaGammaWithCovariance(Ih, FitParam2024, CovMatrix);
    if (R.bg_nominal < 0 || R.bg_up < 0 || R.bg_down < 0) return -1;   // Ih < min value, no solution

    //double First_bg = ZeroBisectionMethod(MIN, bgmin, params);

    // For the upper band
    if (up) {
        double First_bg_up  = ZeroBrentMethod(MIN, R.bg_up, TOLERANCE, R.params_up);
        return p / First_bg_up;
    }
    else if (down) {    // For the lower band
        double First_bg_down = ZeroBrentMethod(MIN, R.bg_down, TOLERANCE, R.params_down);
        return p / First_bg_down;
    }
    
    // Use the parameters associated with the nominal minimum
    double First_bg_nom = ZeroBrentMethod(MIN, R.bg_nominal, TOLERANCE, R.params_nom);

    // check
    for (int i = 0; i < 6; i++) cout << R.params_nom[i] << " ";
    for (int i = 0; i < 6; i++) cout << params[i] << " ";

    return p / First_bg_nom;
}