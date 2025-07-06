//explanation in deepseek
#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int main()
{
    int n, totalPoints;
    float x[MAX], y[MAX], xp;

    cout << "Enter total number of data points: ";
    cin >> totalPoints;

    cout << "Enter x values:\n";
    for (int i = 0; i < totalPoints; i++)
        cin >> x[i];

    cout << "Enter corresponding y values:\n";
    for (int i = 0; i < totalPoints; i++)
        cin >> y[i];

    cout << "Enter degree of interpolating polynomial: ";
    cin >> n;

    if (n >= totalPoints)
    {
        cout << "Polynomial degree must be less than number of data points.\n";
        return 1;
    }
    cout << "Enter value of x to interpolate: ";
    cin >> xp;

    // Step 1: Find the closest (n+1) points
    int closest = 0;
    float minDiff = fabs(xp - x[0]);
    for (int i = 1; i < totalPoints; i++)
    {
        if (fabs(xp - x[i]) < minDiff)
        {
            minDiff = fabs(xp - x[i]);
            closest = i;
        }
    }

    int start = max(0, closest - n / 2);
    if (start + n >= totalPoints)
        start = totalPoints - n - 1;

    float a[MAX][MAX], coeff[MAX];

    // Step 2: Build the augmented matrix
    cout << "\nBuilding the augmented matrix using selected points:\n";
    for (int i = 0; i <= n; i++)
    {
        float xi = x[start + i];
        float yi = y[start + i];
        cout << "Using point (" << xi << ", " << yi << ")\n";

        for (int j = 0; j <= n; j++)
        {
            a[i][j] = pow(xi, j);
        }
        a[i][n + 1] = yi;
    }

    cout << "\nInitial Augmented Matrix:\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            cout << setw(12) << fixed << setprecision(4) << a[i][j] << " ";
        }
        cout << endl;
    }

    // Step 3: Forward Elimination
    for (int k = 0; k <= n - 1; k++)
    {
        if (a[k][k] == 0.0)
        {
            cout << "Zero pivot found. Gaussian elimination fails.\n";
            return -1;
        }

        for (int i = k + 1; i <= n; i++)
        {
            float factor = a[i][k] / a[k][k];
            for (int j = k; j <= n + 1; j++)
            {
                a[i][j] -= factor * a[k][j];
            }
        }

        cout << "\nAfter eliminating column " << k + 1 << ":\n";
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n + 1; j++)
            {
                cout << setw(12) << fixed << setprecision(4) << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Step 4: Back Substitution
    coeff[n] = a[n][n + 1] / a[n][n];
    for (int i = n - 1; i >= 0; i--)
    {
        float sum = 0;
        for (int j = i + 1; j <= n; j++)
        {
            sum += a[i][j] * coeff[j];
        }
        coeff[i] = (a[i][n + 1] - sum) / a[i][i];
    }

    cout << "\nCoefficients of interpolating polynomial:\n";
    for (int i = 0; i <= n; i++)
    {
        cout << "a" << i << " = " << fixed << setprecision(6) << coeff[i] << endl;
    }

    // Step 5: Interpolation
    float yp = 0;
    for (int i = 0; i <= n; i++)
    {
        yp += coeff[i] * pow(xp, i);
    }

    cout << "\nInterpolated value at x = " << xp << " is: " << fixed << setprecision(6) << yp << endl;

    return 0;
}