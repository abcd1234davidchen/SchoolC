#include <iostream>
using namespace std;
int main()
{
    // Define variables, we will change scores here (0 ~ 100)
    int math = 80;
    int physics = 90;
    int chemistry = 70;
    // Compute the average and variance
    double avg = (math + physics + chemistry) * 1.0 / 3;
    double variance = ((math - avg) * (math - avg) + (physics - avg) * (physics - avg) +
                       (chemistry - avg) * (chemistry - avg)) /
                      3;
    // Display
    cout << "Math: " << math << endl;
    cout << "Physics: " << physics << endl;
    cout << "Chemistry: " << chemistry << endl;
    cout << "Average: " << avg << endl;
    cout << "Variance: " << variance << endl;
    return 0;
}
