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

void solveQueens(int n, vector<vector<int>> board, int col)
{
    queue<pair<vector<vector<int>>, int>> q;
    q.push(make_pair(board, 0));
    while (!q.empty())
    {
        pair<vector<vector<int>>, int> front = q.front();
        q.pop();
        vector<vector<int>> currBoard = front.first;
        int currCol = front.second;

        if (currCol == n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << (currBoard[i][j] ? 'Q' : '.') << " ";
                }
                cout << endl;
            }
            cout << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafe(n, i, currCol, currBoard))
            {
                currBoard[i][currCol] = 1;
                q.push(make_pair(currBoard, currCol + 1));
                currBoard[i][currCol] = 0;
            }
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