#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    // define and read n
    int n;
    cin >> n;
    // calculate the coordinate of center cell
    // 0-based indices are used here: 0, 1, ..., n - 1
    int middle = (n - 1) / 2;
    // output the Euclidean distance of each cell in a nested loop
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            double distance = sqrt((i-middle)*(i-middle)+(j-middle)*(j-middle));
            cout << fixed << setprecision(2) << distance;
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}