#include <iostream>
#include <fstream>

using namespace std;

int comb(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    else
        return comb(n - 1, k - 1) + comb(n - 1, k);
}

int main()
{
    int n, k;
    ifstream file("input3.txt");
    for (int i = 0; i < 5; i++)
    {
        file >> n >> k;
        cout << comb(n, k) << endl;
    }
    return 0;
}
