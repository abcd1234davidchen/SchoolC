#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    string name;
    char classNo;
    int year;
    double GPA;
    getline(cin, name);
    cin.clear();
    cin >> classNo;
    cin.clear();
    cin >> year;
    cin.clear();
    cin >> GPA;
    cout << left << setw(20) << "Name" << right << setw(6) << "Class" << right << setw(10) << "Year"
         << right << setw(12) << "GPA" << endl;
    cout << left << setw(20) << name << right << setw(6) << classNo << right << setw(10) << year
         << fixed << setprecision(2) << right << setw(12) << GPA << endl;
}
