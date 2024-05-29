#include <bits/stdc++.h>
using namespace std;

bool isSafe(int n, int row, int col, vector<vector<int>> board)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

void solveQueens(int n, vector<vector<int>>&board, int col)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << (board[i][j] ? " Q " : " . ");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(n, i, col, board))
        {
            board[i][col] = 1;
            solveQueens(n, board, col + 1);
            board[i][col] = 0;
        }
    }
    return;
}

int main()
{
    int n;
    cout << "Enter number of queens:" << endl;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveQueens(n, board, 0);
    return 0;
}