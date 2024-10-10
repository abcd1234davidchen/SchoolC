#include <iostream>
#include <map>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n;
    string buffer;
    cin >> n;
    getline(cin, buffer); // to consume the newline
    getline(cin, buffer); // to consume the empty line

    while (n--) {
        map<string, int> manyTree;
        int treeN = 0;
        string ipt;

        while (getline(cin, ipt) && !ipt.empty()) {
            treeN++;
            manyTree[ipt]++;
        }

        for (const auto& pair : manyTree) {
            cout << fixed << setprecision(4) << pair.first << " " << pair.second * 100.0 / treeN << endl;
        }
        if(n!=0)cout << endl;
    }

    return 0;
}
