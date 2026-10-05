#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    bool correct;
    char op, dump;
    cin >> a >> op >> b >> dump >> c;
    switch (op)
    {
    case '+':
        correct = (a + b) == c;
        break;
    case '-':
        correct = (a - b) == c;
        break;
    case '*':
        correct = (a * b) == c;
        break;
    case '/':
        correct = (a / b) == c;
        break;
    default:
        correct = false;
    }
    if (correct)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}
