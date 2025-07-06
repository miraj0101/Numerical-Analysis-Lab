//Explanation deepseek
#include <bits/stdc++.h>
using namespace std;

int main()
{
    float a[10][11], x[10];
    int n;

    cout << "Enter number of variables: ";
    cin >> n;

    cout << "Enter the coefficients of the augmented matrix (row by row):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "\nInitial Augmented Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << setw(10) << fixed << setprecision(4) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Forward Elimination
    for (int k = 0; k < n - 1; k++)
    {
        if (a[k][k] == 0.0)
        {
            cout << "Zero pivot found. Naive Gaussian elimination fails.\n";
            return -1;
        }

        for (int i = k + 1; i < n; i++)
        {
            float factor = a[i][k] / a[k][k];
            for (int j = k; j <= n; j++)
            {
                a[i][j] = a[i][j] - factor * a[k][j];
            }

            cout << "After eliminating row " << i + 1 << " using row " << k + 1 << ":\n";
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c <= n; c++)
                {
                    cout << setw(10) << fixed << setprecision(4) << a[r][c] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        float sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // Display solution
    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << "=" << fixed << setprecision(6) << x[i] << endl;
    }

    return 0;
}