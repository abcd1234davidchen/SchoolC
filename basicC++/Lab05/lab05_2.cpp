#include <iostream>
using namespace std;

int main()
{
    string power;
    cin >> power;
    if (power == "on")
    {
        int mode;
        cin >> mode;
        switch (mode)
        {
        case 1:
            cout << "陳展皝" << endl;
            break;
        case 2:
            cout << "CS" << endl;
            break;
        case 3:
            cout << "B123245006" << endl;
            break;
        }
    }
    else if (power == "off")
    {
        cout << "standby";
    }
    return 0;
}
