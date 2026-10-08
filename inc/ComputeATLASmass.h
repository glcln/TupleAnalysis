#include <cmath>
#include <iostream>
#include <string>
#include <TMatrixDSym.h>
#include <TMatrixDSymEigen.h>
#include <TVectorD.h>
#include <TF1.h>

using namespace std;

#define TOLERANCE 1e-6
#define MIN 0.3
#define MAX 10000

// -----------------------------------------------------------------------------
// Define here all the parameters and covariance matrix extracted from the fit
// -----------------------------------------------------------------------------

double ATLASfit_data2024[5] = {0.0203934, -24.5532, 0.876953, 5.72139, -2.62575};
double covMatrixATLASfit_data2024[5][5] = {
    {4.93045e-08, 2.10623e-05, 3.17108e-07, -5.05193e-06, -7.42276e-07},
    {2.10623e-05, 0.0108701, 0.00018019, -0.00276258, -0.00054921},
    {3.17108e-07, 0.00018019, 3.52731e-06, -4.2819e-05, -7.8238e-06}, 
    {-5.05193e-06, -0.00276258, -4.2819e-05, 0.000786501, 0.000154737}, 
    {-7.42276e-07, -0.00054921, -7.8238e-06, 0.000154737, 0.000125867 }
};

double ATLASfit_bckg2024[5] = {0.00896484, -28.9796, 0.837418, 6.62379, -2.83299};
double covMatrixATLASfit_bckg2024[5][5] = {
    {2.89207e-10, -2.84835e-10, -4.73491e-09, -1.17769e-08, 4.79617e-09},
    {-2.84835e-10, 2.92697e-09, 3.64143e-09, -1.61219e-08, -5.80983e-09},
    {-4.73491e-09, 3.64143e-09, 9.29662e-08, 4.66886e-07, -7.03278e-08},
    {-1.17769e-08, -1.61219e-08, 4.66886e-07, 5.57153e-06, -4.43662e-08},
    {4.79617e-09, -5.80983e-09, -7.03278e-08, -4.43662e-08, 8.4788e-08}
};

double ATLASfit_glupion2024[5] = {0.0294779,-15.7847,1.42379,5.06116,-2.6255};
double covMatrixATLASfit_glupion2024[5][5] = {
    {1.26429e-07, 9.58137e-09, -1.36143e-06, -8.15125e-07, 1.81316e-06},
    {9.58137e-09, 1.38415e-08, -9.3524e-08, -4.43099e-08, 1.42188e-07},
    {-1.36143e-06, -9.3524e-08, 1.50113e-05, 1.02915e-05, -1.93057e-05},
    {-8.15125e-07, -4.43099e-08, 1.02915e-05, 1.27375e-05, -1.07083e-05},
    {1.81316e-06, 1.42188e-07, -1.93057e-05, -1.07083e-05, 2.66812e-05}
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

double findMinimumX(const double *par) {
    TF1 f("f", AtlasFunction, MIN, MAX, 6);
    for (int i = 0; i < 6; i++) f.FixParameter(i, par[i]);

    // If the minimum is above zero, no physical solution
    // appen if Ih < min value = 2.95863 (corresponding to bg=6.98->if p<6.98*m no solution)
    if (f.Eval(f.GetMinimumX()) > 0) return -1;

    return f.GetMinimumX();
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
    R.bg_nominal = findMinimumX(p_nom);

    double min_up  = R.bg_nominal;
    double min_down = R.bg_nominal;
    // Parameters of the variations defining the envelope, initialised to the nominal ones.
    // They must be independent copies: pointing to p_nom would overwrite the nominal parameters.
    double p_up_end[6];
    double p_down_end[6];
    for (int i=0; i<6; i++) {
        p_up_end[i]   = p_nom[i];
        p_down_end[i] = p_nom[i];
    }

    // --- Loop over each eigen-direction --------------------------------------
    for (int k=0; k<5; k++)
    {
        double sigma_k = sqrt( eigenVal[k] );

        // Build delta parameter vectors
        TVectorD delta(5);
        for (int i=0; i<5; i++)
            delta[i] = eigenVec(i,k) * sigma_k;

        double p_up[6];
        double p_down[6];

        // dEdx stays the same (index 0)
        p_up[0]   = Ih;
        p_down[0] = Ih;

        // Apply p +/- delta
        for (int i=0; i<5; i++) {
            p_up[i+1]   = p0[i] + delta[i];
            p_down[i+1] = p0[i] - delta[i];
        }

        // Compute minima for each variation
        double x_up   = findMinimumX(p_up);
        double x_down = findMinimumX(p_down);

        // Keep envelope: worst-case shifts
        if (x_up   > min_up) {
            min_up   = x_up;
            p_up_end[0] = Ih;
            for (int i=0; i<5; i++) p_up_end[i+1] = p_up[i+1];
        }
        if (x_down < min_down) {
            min_down = x_down;
            p_down_end[0] = Ih;
            for (int i=0; i<5; i++) p_down_end[i+1] = p_down[i+1];
        }
    }

    // --- Final asymmetric uncertainties ---------------------------------------
    R.bg_up   = min_up;
    R.bg_down = min_down;

    for (int i = 0; i < 6; i++) {
        R.params_nom[i]  = p_nom[i];       // nominal
        R.params_up[i]   = p_up_end[i];        // upper
        R.params_down[i] = p_down_end[i];      // lower
    }

    return R;
}


// -----------------------------------------------------------------------------
// Find zero of the function using Brent's Method
// https://people.math.sc.edu/Burkardt/cpp_src/brent/brent.html#:~:text=BRENT%2C%20a%20C%2B%2B%20library%20which,that%20the%20function%20is%20differentiable
// -----------------------------------------------------------------------------
double ZeroBrentMethod (double a, double b, double t, const double *params) {
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
    fa = f.Eval(sa);
    fb = f.Eval(sb);

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

        fb = f.Eval(sb);

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
double findMass(const double p, 
                const double Ih,
                const std::string year,
                bool up=false, 
                bool down=false) {
    TMatrixDSym CovMatrix = TMatrixDSym(5);
    double *params = nullptr;
    if (year == "2024data") {
        params = ATLASfit_data2024;
        CovMatrix = InitializeCovMatrix(covMatrixATLASfit_data2024);
    }
    else if (year == "2024bkg") {
        params = ATLASfit_bckg2024;
        CovMatrix = InitializeCovMatrix(covMatrixATLASfit_bckg2024);
    }
    else if (year == "2024glupion") {
        params = ATLASfit_glupion2024;
        CovMatrix = InitializeCovMatrix(covMatrixATLASfit_glupion2024);
    }
    else {
        cerr << "Error: Year not recognized. Use '2024' or '2018'." << endl;
        return -1;
    }

    BetaGammaMinResult R = findBetaGammaWithCovariance(Ih, params, CovMatrix);
    if (R.bg_nominal < 0 || R.bg_up < 0 || R.bg_down < 0) return -1;   // Ih < min value, no solution

    if (up) {           // For the upper band
        double First_bg_up = ZeroBrentMethod(MIN, R.bg_up, TOLERANCE, R.params_up);
        return p / First_bg_up;
    }
    else if (down) {    // For the lower band
        double First_bg_down = ZeroBrentMethod(MIN, R.bg_down, TOLERANCE, R.params_down);
        return p / First_bg_down;
    }
    
    // Use the parameters associated with the nominal minimum
    double First_bg_nom = ZeroBrentMethod(MIN, R.bg_nominal, TOLERANCE, R.params_nom);

    return p / First_bg_nom;
}