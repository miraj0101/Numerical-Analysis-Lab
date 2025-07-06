#include <bits\stdc++.h>
using namespace std;

// Function: f(x) = 3x - cos(x) - 1
double f(double x)
{
    return 3 * x - cos(x) - 1;
}
// Derivative: f'(x) = 3 + sin(x)
double df(double x)
{
    return 3 + sin(x);
}
//Newton-Raphson function
void newtonRaphson(double x0, int maxIterations, double stopError, bool useError)
{
    double xNew = x0, xOld, error = 100;
    cout << setw(10) << "Iter" << setw(15) << "x" << setw(20) << "f(x)" << setw(15) << "Error(%)" << endl;
    for (int i = 1; i <= maxIterations; ++i)
    {
        xOld = xNew;
        double fx = f(xOld);
        double dfx = df(xOld);

        if (dfx == 0)
        {
            cout << "Derivative zero! Cannot continue." << endl;
            return;
        }
        xNew = xOld - fx / dfx;  //Newton Raphson formula
        cout << setw(10) << i<< setw(15) << fixed << setprecision(6) << xNew<< setw(20) << f(xNew);
        if (i > 1)
        {
            error = fabs((xNew - xOld) / xNew) * 100;
            cout << setw(15) << error << endl;

            if (useError && error < stopError)
                break;
        }
        else
        {
            cout << setw(15) << "-" << endl;
        }
    }

    cout << "\nApproximate root: " << fixed << setprecision(6) << xNew << endl;
}

int main()
{
    double x0;
    int choice;
    cout << "Enter initial guess x0: ";
    cin >> x0;
    cout << "\nChoose an option:\n";
    cout << "1. Fixed number of iterations\n";
    cout << "2. Stop when Approximate Error is small enough\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int n;
        cout << "Enter number of iterations: ";
        cin >> n;
        newtonRaphson(x0, n, 0.0, false);
        break;
    }
    case 2:
    {
        double approxError;
        cout << "Enter maximum approximate error (e.g., 0.01): ";
        cin >> approxError;
        newtonRaphson(x0, 1000, approxError, true); // max 1000 iterations
        break;
    }
    default:
        cout << "Invalid choice! Please enter 1 or 2.\n";
    }

    return 0;
}
