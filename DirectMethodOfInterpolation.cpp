#include <iostream>
#include <iomanip>

using namespace std;

// Lagrange Interpolation function
double lagrangeInterpolation(double x[], double y[], int n, double xp)
{
    double yp = 0;

    for (int i = 0; i < n; i++)
    {
        double term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += term;
    }

    return yp;
}

int main()
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n];

    cout << "Enter data points (x[i] and y[i]) in one line:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "x[" << i << "] y[" << i << "]: ";
        cin >> x[i] >> y[i];
    }

    double xp;
    cout << "\nEnter the value of x for interpolation: ";
    cin >> xp;

    double yp = lagrangeInterpolation(x, y, n, xp);

    cout << fixed << setprecision(6);
    cout << "\nInterpolated value at x = " << xp << " is y = " << yp << endl;

    return 0;
}
