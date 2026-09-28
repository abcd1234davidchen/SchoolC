#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    // define variables and read the input data
    double f1, f2;
    cin >> f1 >> f2;
    // calculate the magnitude difference with log10() function
    double mag = -2.5 * log10(f1 / f2);
    // format output and display
    cout << fixed << setprecision(4) << "Magnitude Difference: " << mag;
    return 0;
}
