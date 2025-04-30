# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iostream>
# include "TF1.h"

using namespace std;

#define TOLERANCE 1e-6
#define MAX_ITER 1000

#define MIN 0.3
#define MAX 100


double AtlasFunction(double *x, double *par)
{
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

double findXmin(const double inf, const double sup, const double *params)
{
    TF1 *f = new TF1("f", AtlasFunction, inf, sup, 6);
    f->FixParameter(0, params[0]); // dEdx
    f->FixParameter(1, params[1]);
    f->FixParameter(2, params[2]);
    f->FixParameter(3, params[3]);
    f->FixParameter(4, params[4]);
    f->FixParameter(5, params[5]);

    if ( f->Eval(f->GetMinimumX()) > 0)
    {
        cout << "               WARNING" << endl;
        cout << "[inf, sup] -> [f(inf), f(sup)] : " << "[" << inf << " , " << sup << "] -> [" << f->Eval(inf) << " , " << f->Eval(sup) << "]" << endl;
        cout << "min , f(min) -> " << f->GetMinimumX() << " , " << f->Eval(f->GetMinimumX()) << endl;
    }

    return f->GetMinimumX();
}

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

    if (fa * fb >= 0)
    {
        cout << "[a , b] -> [f(a) , f(b)] : " << "[" << a << " , " << b << "] -> [" << fa << " , " << fb << "]" << endl;    
        return -1;
    }



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

// https://people.math.sc.edu/Burkardt/cpp_src/brent/brent.html#:~:text=BRENT%2C%20a%20C%2B%2B%20library%20which,that%20the%20function%20is%20differentiable.
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

    TF1 *f = new TF1("f", AtlasFunction, a, b, 6);
    f->FixParameter(0, params[0]); // dEdx
    f->FixParameter(1, params[1]);
    f->FixParameter(2, params[2]);
    f->FixParameter(3, params[3]);
    f->FixParameter(4, params[4]);
    f->FixParameter(5, params[5]);


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

double findMass(const double p, const double Ih)
{
    double params[6] = {Ih, 0.00669857, -26.6212, 0.989545, 6.88361, -2.84246};

    double bgmin = findXmin(MIN, MAX, params);
    //double First_bg = ZeroBisectionMethod(MIN, bgmin, params);
    double First_bg = ZeroBrentMethod(MIN, bgmin, TOLERANCE, params);
    
    return p / First_bg;
}