#include <iostream>
#include <vector>
using namespace std;

class BoxOfProduce {
private:
    vector<string> bundles;

public:
    BoxOfProduce() {}

    void addBundle(string bundle) {
        bundles.push_back(bundle);
    }

    vector<string> getBundles() {
        return bundles;
    }

    void output() {
        for (string bundle : bundles) {
            cout << bundle << endl;
        }
    }

    BoxOfProduce operator+(const BoxOfProduce& other) {
        BoxOfProduce newBox;
        newBox.bundles = bundles;
        for (string bundle : other.bundles) {
            newBox.bundles.push_back(bundle);
        }
        return newBox;
    }
};

int main() {
    BoxOfProduce box1;
    box1.addBundle("Apples");
    box1.addBundle("Oranges");

    BoxOfProduce box2;
    box2.addBundle("Bananas");
    box2.addBundle("Grapes");

    BoxOfProduce box3 = box1 + box2;

    box3.output();

    return 0;
}