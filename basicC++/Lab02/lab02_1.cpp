#include <iostream>
using namespace std;
int main()
{
    // Define variables, we will change matrix elements here (-10 ~ 10)
    int a = 4;
    int b = 7;
    int c = 2;
    int d = 6;
    // Compute the determinant
    int det = a * d - b * c;
    // Compute the inverse matrix
    double val1 = d * 1.0 / det;
    double val2 = b * -1.0 / det;
    double val3 = c * -1.0 / det;
    double val4 = a * 1.0 / det;
    // Display
    cout << "Original Matrix" << endl;
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    cout << "Inverse Matrix" << endl;
    cout << val1 << " " << val2 << endl;
    cout << val3 << " " << val4 << endl;
    return 0;
}
