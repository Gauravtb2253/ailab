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

void print()
{
    for (int i = 1; i <= 9; i++)
    {
        if (BOARD[i] == 2)
        {
            cout << "|"
                 << "-"
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
    return;
}

int posswin(int pl)
{
    if (pl == 3 && pl1.size() >= 2)
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
    else if (pl == 5 && pl2.size() >= 2)
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
                            cout << k << endl;
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
    int r = rand() % 10;
    if (BOARD[r] != 2 || r == 0)
    {
        return make2();
    }
    return r;
}

void GO(int pl, int n)
{
    cout << "TURN:" << TURN << endl;
    if (BOARD[n] == 2)
    {
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
        print();
    }
    else
    {
        cout << "NO cheating re-enter valid move !!!" << endl;
        int a;
        cin >> a;
        GO(pl, a);
    }
}

void checkifuserwins(int pl)
{
    int req = 3 * pl;
    for (int i = 0; i < 3; i++)
    {
        if (BOARD[3 * (i) + 1] + (BOARD[3 * (i) + 2] + BOARD[3 * (i) + 3]) == req && BOARD[3 * (i) + 1] == pl && (BOARD[3 * (i) + 2] == pl && BOARD[3 * (i) + 3] == pl))
        {
            cout << "U win COngratulations!!" << endl;
            TURN = 11;
        }
        if ((BOARD[i + 1] + (BOARD[i + 4] + BOARD[i + 7]) == req) && BOARD[i + 1] == pl && BOARD[i + 4] == pl && BOARD[i + 7] == pl)
        {
            cout << "U win COngratulations!!" << endl;
            TURN = 11;
        }
    }
    if (BOARD[1] + (BOARD[5] + BOARD[9]) == req && BOARD[1] == pl && BOARD[5] == pl && BOARD[9] == pl)
    {
        cout << "U win COngratulations!!" << endl;
        TURN = 11;
    }
    if (BOARD[3] + (BOARD[5] + BOARD[7]) == req && BOARD[3] == pl && BOARD[5] == pl && BOARD[7] == pl)
    {
        cout << "U win COngratulations!!" << endl;
        TURN = 11;
    }
    return;
}

void GAME()
{
    int a;
    cout << "ENTER 3 IF U WANT TO PLAY 'X'\n 5 IF U WANT TO PLAY 'O'" << endl;
    cin >> a;
    int n;
    print();
    if (a == 3)
    {
        while (TURN <= 9)
        {
            cout << "Enter where u want to place input: " << endl;
            cin >> n;
            GO(3, n);
            checkifuserwins(3);
            if (TURN == 11 || TURN == 10)
            {
                break;
            }
            cout << "Computer played its move" << endl;
            if (posswin(5) != 0)
            {
                GO(5, posswin(5));
                TURN = 11;
                cout << "U LOSE BETTER LUCK NEXT TIME!!" << endl;
            }
            else if (posswin(3) != 0)
            {
                GO(5, posswin(3));
            }
            else
            {
                GO(5, make2());
            }
        }
        if (TURN == 10)
        {
            cout << "This is a draw" << endl;
        }
        print();
    }
    else if (a == 5)
    {
        while (TURN <= 9)
        {
            cout << "Computer played its move" << endl;
            if (posswin(3) != 0)
            {
                GO(3, posswin(3));
                TURN = 11;
                cout << "U LOSE BETTER LUCK NEXT TIME!!" << endl;
                break;
            }
            else if (posswin(5) != 0)
            {
                GO(3, posswin(5));
            }
            else
            {
                GO(3, make2());
            }
            if (TURN == 11 || TURN == 10)
            {
                break;
            }
            cout << "Enter where u want to place input: " << endl;
            cin >> n;
            GO(5, n);
            checkifuserwins(5);
        }
        if (TURN == 10)
        {
            cout << "This is a draw" << endl;
            print();
            return;
        }
        print();
    }
    else
    {
        cout << "ENTER VALID INPUT !!!!!!!!!!!!!!!!!!!!" << endl;
        GAME();
    }
}

int main()
{
    srand(time(0));
    GAME();
    return 0;
}