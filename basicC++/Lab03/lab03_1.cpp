#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int recA1, recA2;
    int recB1, recB2;
    int recC1, recC2;
    ifstream iff;
    iff.open("data.txt");
    iff >> recA1 >> recA2;
    iff.clear();
    iff >> recB1 >> recB2;
    iff.clear();
    iff >> recC1 >> recC2;
    cout << "Area: " << recA1 * recA2 << " Perimeter: " << (recA1 + recA2) * 2 << endl;
    cout << "Area: " << recB1 * recB2 << " Perimeter: " << (recB1 + recB2) * 2 << endl;
    cout << "Area: " << recC1 * recC2 << " Perimeter: " << (recC1 + recC2) * 2 << endl;
}
