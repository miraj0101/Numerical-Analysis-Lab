#include <bits\stdc++.h>
using namespace std;

// Define the function f(x) = 3x - cos(x) - 1
double f(double x)
{
    return 3 * x - cos(x) - 1;
}
//Bisection function
void bisection(double a, double b, int maxIterations, double stopError, bool useError)
{
    double xOld = 0, xNew = 0, error = 100;
    cout << setw(10) << "Iter" << setw(12) << "a" << setw(12) << "b"
         << setw(12) << "x" << setw(15) << "Error(%)" << endl;
    for (int i = 1; i <= maxIterations; ++i)
    {
        xNew = (a + b) / 2.0;

        cout << setw(10) << i<< setw(12) << fixed << setprecision(6) << a<< setw(12) << b<< setw(12) << xNew;

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

        if (f(xNew) == 0)
            break;
        else if (f(a) * f(xNew) < 0)
            b = xNew;
        else
            a = xNew;

        xOld = xNew;
    }

    cout << "\nApproximate root: " << fixed << setprecision(6) << xNew << endl;
}

int main()
{
    double a, b;
    int choice;
    // Keep asking until valid a and b are given
    while (true)
    {
        cout << "Enter lower bound (a): ";
        cin >> a;
        cout << "Enter upper bound (b): ";
        cin >> b;
        if (f(a) * f(b) < 0)
            break;
        else
            cout << "Invalid interval! f(a) and f(b) must have opposite signs.\n\n";
    }
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
        bisection(a, b, n, 0.0, false);
        break;
    }
    case 2:
    {
        double approxError;
        cout << "Enter maximum approximate error (e.g., 0.01): ";
        cin >> approxError;
        bisection(a, b, 1000, approxError, true); // max 1000 iterations for safety
        break;
    }
    default:
        cout << "Invalid choice! Please enter 1 or 2.\n";
    }
    return 0;
}
