#include <iostream>
using namespace std;

int main()
{
    int arrA[20];
    int arrB[20];
    int size = 0;
    int sum = 0;

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arrA[i];
    }
    for (int i = 0; i < size; i++)
    {
        cin >> arrB[i];
    }
    for (int i = 0; i < size; i++)
    {
        sum += arrA[i] * arrB[i];
    }
    cout << sum << endl;
}
