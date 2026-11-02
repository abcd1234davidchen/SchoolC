#include <iostream>
#include <fstream>
using namespace std;
// TODO
//  Complete the function here
bool shouldSwap(int left, int right)
{
    return left > right;
}
int main()
{
    ifstream fin("data.txt");
    int n, m;
    int arr[100];
    fin >> n;
    for (int t = 0; t < n; t++)
    {
        fin >> m;
        // Read array elements
        for (int k = 0; k < m; k++)
        {
            fin >> arr[k];
        }
        // TODO
        //  Insertion Sort
        for (int i = 1; i < m; i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (shouldSwap(arr[j-1],arr[j]))
                {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
                else
                {
                    break;
                }
            }
        }
        // Print the sorted array
        for (int k = 0; k < m; k++)
        {
            if (k > 0)
                cout << " ";
            cout << arr[k];
        }
        cout << endl;
    }
    fin.close();
    return 0;
}