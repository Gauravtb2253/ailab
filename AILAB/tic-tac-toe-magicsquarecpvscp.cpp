#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>
using namespace std;

vector<int> BOARD(10, 2);
vector<int> magicsquare = {0, 8, 3, 4, 1, 5, 9, 6, 7, 2};
vector<int> pl1;
vector<int> pl2;
int TURN = 1;

int posswin(int pl)
{
    if (pl == 3)
    {
        for (int i = 0; i < pl1.size() - 1; i++)
        {
            for (int j = i + 1; j < pl1.size(); j++)
            {
                int diff = 15 - (magicsquare[pl1[i]] + magicsquare[pl1[j]]);
                if (diff > 0 && diff <= 9)
                {
                    for (int k = 1; k < magicsquare.size(); k++)
                    {
                        if (magicsquare[k] == diff && BOARD[k] == 2)
                        {
                            return k;
                        }
                    }
                }
            }
        }
    }
    else if (pl == 5)
    {
        for (int i = 0; i < pl2.size() - 1; i++)
        {
            for (int j = i + 1; j < pl2.size(); j++)
            {
                int diff = 15 - (magicsquare[pl2[i]] + magicsquare[pl2[j]]);
                if (diff > 0 && diff <= 9)
                {
                    for (int k = 1; k < magicsquare.size(); k++)
                    {
                        if (magicsquare[k] == diff && BOARD[k] == 2)
                        {
                            return k;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int make2()
{
    if (BOARD[5] == 2)
    {
        return 5;
    }
    vector<int> make = {2, 4, 6, 8};
    int r = rand() % 4;
    return make[r];
}

void GO(int pl, int n)
{
    cout << "TURN:" << TURN << endl;
    TURN++;
    BOARD[n] = pl;
    if (pl == 3)
    {
        pl1.push_back(n);
    }
    else if (pl == 5)
    {
        pl2.push_back(n);
    }
    for (int i = 1; i <= 9; i++)
    {
        if (BOARD[i] == 2)
        {
            cout << "|"
                 << " "
                 << "|";
        }
        else if (BOARD[i] == 5)
        {
            cout << "|"
                 << "O"
                 << "|";
        }
        else if (BOARD[i] == 3)
        {
            cout << "|"
                 << "X"
                 << "|";
        }
        else
        {
            cout << "|" << BOARD[i] << "|";
        }
        if (i % 3 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

void GAME()
{
    while (TURN <= 9)
    {
        switch (TURN)
        {
        case 1:
            GO(3, 1);
            break;
        case 2:
            if (BOARD[5] == 2)
            {
                GO(5, 5);
            }
            else
            {
                GO(5, 3);
            }
            break;
        case 3:
            if (BOARD[9] = 2)
            {
                GO(3, 9);
            }
            else
            {
                GO(3, 3);
            }
            break;
        case 4:
            if (posswin(3) != 0)
            {
                GO(5, posswin(3));
            }
            else
            {
                GO(5, make2());
            }
            break;
        case 5:
            if (posswin(3) != 0)
            {
                GO(3, posswin(3));
                cout << "X wins" << endl;
                TURN = 11;
                break;
            }
            else if (posswin(5) != 0)
            {
                GO(3, posswin(5));
            }
            else if (BOARD[7] == 2)
            {
                GO(3, 7);
            }
            else
            {
                GO(3, 3);
            }
            break;
        case 6:
            if (posswin(5) != 0)
            {
                GO(5, posswin(5));
                cout << "O wins" << endl;
                TURN = 11;
                break;
            }
            else if (posswin(3) != 0)
            {
                GO(5, posswin(3));
            }
            else
            {
                GO(5, make2());
            }
            break;
        case 7:
            if (posswin(3) != 0)
            {
                GO(3, posswin(3));
                cout << "X wins" << endl;
                TURN = 11;
                break;
            }
            else if (posswin(5) != 0)
            {
                GO(3, posswin(5));
            }
            else
            {
                for (int i = 1; i < 10; i++)
                {
                    if (BOARD[i] == 2)
                    {
                        GO(3, i);
                        break;
                    }
                }
            }
            break;
        case 8:
            if (posswin(5) != 0)
            {
                GO(5, posswin(5));
                cout << "O wins" << endl;
                TURN = 11;
                break;
            }
            else if (posswin(3) != 0)
            {
                GO(5, posswin(3));
            }
            else
            {
                for (int i = 1; i < 10; i++)
                {
                    if (BOARD[i] == 2)
                    {
                        GO(5, i);
                        break;
                    }
                }
            }
            break;
        case 9:
            if (posswin(3) != 0)
            {
                GO(3, posswin(3));
                cout << "X wins" << endl;
                TURN = 11;
                break;
            }
            else if (posswin(5) != 0)
            {
                GO(3, posswin(5));
            }
            else
            {
                for (int i = 1; i < 10; i++)
                {
                    if (BOARD[i] == 2)
                    {
                        GO(3, i);
                        break;
                    }
                }
            }
            break;
        default:
            break;
        }
    }

    if (TURN == 10)
    {
        cout << "This is a draw" << endl;
    }
    // for (int i = 0; i < pl1.size(); i++)
    // {
    //     cout << pl1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < pl2.size(); i++)
    // {
    //     cout << pl2[i] << " ";
    // }
    cout << endl;
}

int main()
{
    srand(time(0));
    GAME();
    return 0;
}