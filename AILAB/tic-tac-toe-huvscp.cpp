#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

vector<int> BOARD(10, 2);
int TURN = 1;

void print()
{
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
    return;
}

int posswin(int pl)
{
    int req = pl * pl * 2;

    for (int i = 0; i < 3; i++)
    {
        if (BOARD[3 * (i) + 1] * (BOARD[3 * (i) + 2] * BOARD[3 * (i) + 3]) == req)
        {
            for (int j = 0; j < 3; j++)
            {
                if (BOARD[3 * (i) + j + 1] == 2)
                    return 3 * (i) + j + 1;
            }
        }
        if (BOARD[i + 1] * (BOARD[i + 4] * BOARD[i + 7]) == req)
        {
            for (int j = 0; j < 3; j++)
            {
                if (BOARD[i + 3 * (j) + 1] == 2)
                    return 3 * (j) + i + 1;
            }
        }
    }
    // diagonals
    if (BOARD[1] * (BOARD[5] * BOARD[9]) == req)
    {
        if (BOARD[1] == 2)
            return 1;
        if (BOARD[5] == 2)
            return 5;
        if (BOARD[9] == 2)
            return 9;
    }
    if (BOARD[3] * (BOARD[5] * BOARD[7]) == req)
    {
        if (BOARD[3] == 2)
            return 3;
        if (BOARD[5] == 2)
            return 5;
        if (BOARD[7] == 2)
            return 7;
    }

    // if not found
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