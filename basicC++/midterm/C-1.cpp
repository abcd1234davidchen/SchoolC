#include <iostream>
#include <fstream>
using namespace std;
// TODO
//  Complete the function here
bool shouldSwap(int left,int right)
{
    return left>right;
}
int main()
{
    ifstream fin("data.txt");
    int left, right;
    for (int i = 0; i < 5; i++)
    {
        fin >> left >> right;
        // TODO
        if (shouldSwap(left,right))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    fin.close();
    return 0;
}