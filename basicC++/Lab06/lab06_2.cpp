#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // define and read N
    int N;
    cin >> N;
    // repeatedly read N match results in a loop statement
    int numWin = 0;
    int numLoss = 0;
    char currMatch;
    for (int i = 0; i < N; i++)
    {
        cin >> currMatch;
        if (currMatch == 'W')
            numWin++;
        else if (currMatch == 'L')
            numLoss++;
    }
    // calculate the win rate, don’t forget about type casting
    double winrate = numWin * 1.0 / (numWin + numLoss) * 100;
    // format output and display
    cout << "Wins: " << numWin << endl;
    cout << "Losses: " << numLoss << endl;
    cout << "Win Rate: " << fixed << setprecision(2) << winrate << "%" << endl;
    return 0;
}
