#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    // define and read in the input from terminal
    double x;
    cin >> x;
    // calculate the outputs of each activation function
    double relu, sigmoid, softsign;
    relu = max(0.0, x);
    sigmoid = 1.0 / (1 + exp(x * (-1.0)));
    softsign = x * 1.0 / (1 + fabs(x));
    // format output and display
    cout << fixed << setprecision(4) << "ReLU: " << relu << endl
         << "Sigmoid: " << sigmoid << endl
         << "Softsign: " << softsign << endl;
    return 0;
}
