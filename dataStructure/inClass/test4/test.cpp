#include <iostream>
#include <string>

void permute(std::string str, int l, int r) {
    if (l == r) {
        std::cout << str << std::endl;
    } else {
        for (int i = l; i <= r; i++) {
            std::swap(str[l], str[i]);
            permute(str, l + 1, r);
            std::swap(str[l], str[i]); // backtrack
        }
    }
}

int main() {
    std::string str = "ABCDE";
    int n = str.size();
    permute(str, 0, 3);
    return 0;
}