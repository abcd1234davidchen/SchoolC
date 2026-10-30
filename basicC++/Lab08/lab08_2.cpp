#include <iostream>
using namespace std;

void CreateInitialPlayfield(char playfield[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> playfield[i][j];
        }
    }
}

bool isFull(const char line[10])
{
    for (int i = 0; i < 10; i++)
    {
        if (line[i] == '.')
        {
            return false;
        }
    }
    return true;
}

void PrintPlayfield(const char playfield[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << playfield[i][j];
        }
        cout << endl;
    }
}

int main()
{
    char playfield[10][10];
    CreateInitialPlayfield(playfield);

    if (isFull(playfield[0]))
    {
        for (int i = 0; i < 10; i++)
        {
            playfield[0][i] = '.';
        }
    }
    for (int i = 1; i < 10; i++)
    {
        if (isFull(playfield[i]))
        {
            for (int j = i - 1; j >= 0; --j)
            {
                for (int k = 0; k < 10; ++k)
                {
                    playfield[j + 1][k] = playfield[j][k];
                }
            }
            for (int k = 0; k < 10; ++k)
            {
                playfield[0][k] = '.';
            }
        }
    }

    PrintPlayfield(playfield);
    return 0;
}
