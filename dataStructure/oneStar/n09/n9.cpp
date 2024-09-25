#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    char ct[] = " 234567890-=ertyuiop[]\\dfghjkl;'cvbnm,./";
    char pt[] = " `1234567890qwertyuiop[asdfghjklzxcvbnm,";

    string ipt;
    while (getline(cin, ipt)) {
        for (size_t i = 0; i < ipt.size(); i++) {
            int ch = -1;
            for (int j = 0; j < 41; j++) {
                if (ct[j] == tolower(ipt[i])) {
                    ch = j;
                    break;
                }
            }
            if (ch != -1) {
                cout << pt[ch];
            }
            else {
                cout << ipt[i];
            }
        }
        cout << endl;
    }

    return 0;
}