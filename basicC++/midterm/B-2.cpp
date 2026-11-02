#include <iostream>
#include <string>

using namespace std;
char decrypt(char c, int shift)
{
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++)
    {
        if (c == upper[i])
        {
            return upper[(i - shift + 26) % 26];
        }
        if (c == lower[i])
        {
            return lower[(i - shift + 26) % 26];
        }
    }
    return c;
}
int main()
{
    string s;
    int shift;
    getline(cin, s);
    cin >> shift;
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = decrypt(s[i], shift);
    }
    cout << s << endl;
    return 0;
}