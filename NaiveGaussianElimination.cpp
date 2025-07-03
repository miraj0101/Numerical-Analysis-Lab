#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void printMatrix(double **mat, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= n; ++j) {
            cout << setw(10) << fixed << setprecision(4) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void gaussianElimination(int n, double **mat) {
    cout << "\n=== Forward Elimination Steps ===\n";
    for (int k = 0; k < n - 1; ++k) {
        for (int i = k + 1; i < n; ++i) {
            if (fabs(mat[k][k]) < 1e-12) {
                cout << "Division by zero detected! Aborting.\n";
                return;
            }
            double factor = mat[i][k] / mat[k][k];
            for (int j = k; j <= n; ++j) {
                mat[i][j] -= factor * mat[k][j];
            }
        }
        cout << "\nMatrix after step " << k + 1 << ":\n";
        printMatrix(mat, n);
    }

    // Back Substitution
    double *x = new double[n];
    for (int i = n - 1; i >= 0; --i) {
        x[i] = mat[i][n];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= mat[i][j] * x[j];
        }
        if (fabs(mat[i][i]) < 1e-12) {
            cout << "Division by zero detected during back substitution! Aborting.\n";
            delete[] x;
            return;
        }
        x[i] /= mat[i][i];
    }

    // Display Solution
    cout << "\n=== Solution ===\n";
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
    }

    delete[] x;
}

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    // Dynamic allocation of matrix
    double **mat = new double *[n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new double[n + 1];
    }

    cout << "Enter the augmented matrix (each row in one line):\n";
    cout << "Format: a1 a2 ... an b (where b is the RHS)\n\n";

    for (int i = 0; i < n; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= n; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << "\nInitial Augmented Matrix:\n";
    printMatrix(mat, n);

    gaussianElimination(n, mat);

    // Free memory
    for (int i = 0; i < n; ++i)
        delete[] mat[i];
    delete[] mat;

    return 0;
}
