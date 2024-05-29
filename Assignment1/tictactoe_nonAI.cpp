#include <iostream>
#include <vector>
using namespace std;

vector<int> board(10, 2);
int turn = 1;

int make2()
{
    if (board[5] == 2)
    {
        return 5;
    }
    else if (board[2] == 2)
    {
        return 2;
    }
    else if (board[4] == 2)
    {
        return 4;
    }
    else if (board[6] == 2)
    {
        return 6;
    }
    else if (board[8] == 2)
    {
        return 8;
    }
    else
    {
        int r = rand() % 10;
        if (board[r] != 2 || r == 0 || r % 2 == 0)
        {
            return make2();
        }
        return r;
    }
}

int posswin(int player)
{
    int target = player * player * 2;
    //rows and columns
    for (int i = 0; i < 3; i++)
    {
        if (board[3 * (i) + 1] * (board[3 * (i) + 2] * board[3 * (i) + 3]) == target)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[3 * (i) + j + 1] == 2)
                    return 3 * (i) + j + 1;
            }
        }
        if (board[i + 1] * (board[i + 4] * board[i + 7]) == target)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i + 3 * (j) + 1] == 2)
                    return 3 * (j) + i + 1;
            }
        }
    }
    // diagonals
    if (board[1] * (board[5] * board[9]) == target)
    {
        if (board[1] == 2)
            return 1;
        if (board[5] == 2)
            return 5;
        if (board[9] == 2)
            return 9;
    }
    if (board[3] * (board[5] * board[7]) == target)
    {
        if (board[3] == 2)
            return 3;
        if (board[5] == 2)
            return 5;
        if (board[7] == 2)
            return 7;
    }

    // if not found
    return 0;
}

void printGrid()
{
    cout << "---------------" << endl;
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 2)
        {
            cout << "|"
                 << "   "
                 << "|";
        }
        else if (board[i] == 5)
        {
            cout << "|"
                 << " O "
                 << "|";
        }
        else if (board[i] == 3)
        {
            cout << "|"
                 << " X "
                 << "|";
        }
        if (i % 3 == 0)
        {
            cout << endl
                 << "---------------" << endl;
        }
    }
    cout << endl;
}

void go(int player, int n)
{
    if (board[n] == 2)
    {
        turn++;
        board[n] = player;
        printGrid();
    }
    else
    {
        cout << "Position not available, enter again" << endl;
        int a;
        cin >> a;
        go(player, a);
    }
}

void userWin(int player)
{
    int target = 3 * player;
    for (int i = 0; i < 3; i++)
    {
        if (board[3 * (i) + 1] + (board[3 * (i) + 2] + board[3 * (i) + 3]) == target && board[3 * (i) + 1] == player && (board[3 * (i) + 2] == player && board[3 * (i) + 3] == player))
        {
            cout << "YOU WIN!!" << endl;
            turn = 11;
        }
        if ((board[i + 1] + (board[i + 4] + board[i + 7]) == target) && board[i + 1] == player && board[i + 4] == player && board[i + 7] == player)
        {
            cout << "YOU WIN!!" << endl;
            turn = 11;
        }
    }
    if (board[1] + (board[5] + board[9]) == target && board[1] == player && board[5] == player && board[9] == player)
    {
        cout << "YOU WIN!!" << endl;
        turn = 11;
    }
    if (board[3] + (board[5] + board[7]) == target && board[3] == player && board[5] == player && board[7] == player)
    {
        cout << "YOU WIN!!" << endl;
        turn = 11;
    }
    return;
}

int main()
{
    cout << endl
         << endl;
         
    cout << "You are 'X', PC is 'O'" << endl;
    int n;
    printGrid();

    while (turn <= 9)
    {
        cout << "Where do u want to place X: " << endl;
        cin >> n;
        if (n < 1 || n > 9 || board[n] != 2)
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        go(3, n);
        userWin(3);
        if (turn == 11 || turn == 10)
        {
            break;
        }
        cout << "PC played 'O'" << endl;
        if (posswin(5) != 0)
        {
            go(5, posswin(5));
            turn = 11;
            cout << "U LOSE, BETTER LUCK NEXT TIME!!" << endl;
        }
        else if (posswin(3) != 0)
        {
            go(5, posswin(3));
        }
        else
        {
            go(5, make2());
        }
    }
    if (turn == 10)
    {
        cout << "MATCH DRAW" << endl;
    }
    printGrid();
    return 0;
}