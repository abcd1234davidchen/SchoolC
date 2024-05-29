#include <iostream>
#include <fstream>

using namespace std;

void outAverageMileage(int mileage1, int mileage2, int mileage3, ofstream &outputFile) {
    outputFile << (mileage1 + mileage2 + mileage3) / 3.0 << "\n";
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    string make, model;
    int mileage1, mileage2, mileage3;

    while (inputFile >> make >> model >> mileage1 >> mileage2 >> mileage3) {
        outputFile << make << " " << model << " " << mileage1 << " " << mileage2 << " " << mileage3<<" ";
        outAverageMileage(mileage1, mileage2, mileage3, outputFile);
    }

    inputFile.close();
    outputFile.close();

    return 0;
}