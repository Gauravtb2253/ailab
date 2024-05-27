#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    // Check left side of this row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    // Check upper diagonal on left side
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j])
        {
            return false;
        }
        i--;
        j--;
    }

    // Check lower diagonal on left side
    i = row;
    j = col;
    while (j >= 0 && i < n)
    {
        if (board[i][j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

bool isFound = false;

bool solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    queue<pair<vector<vector<int>>, int>> q;
    q.push(make_pair(board, 0));

    while (!q.empty())
    {
        pair<vector<vector<int>>, int> front = q.front();
        q.pop();
        vector<vector<int>> &curBoard = front.first;
        int curCol = front.second;

        if (curCol == n)
        {
            isFound = true;
            // Print
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << (curBoard[i][j] ? 'Q' : '.') << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafe(curBoard, i, curCol, n))
            {
                curBoard[i][curCol] = 1;
                q.push(make_pair(curBoard, curCol + 1));
                curBoard[i][curCol] = 0;
            }
        }
    }

    return isFound;
}

int main()
{
    int n;
    cout << "Enter the value of n for the N-Queens problem: ";
    cin >> n;
    if (!solveNQueens(n))
    {
        cout << "Solution does not exist for n = " << n << endl;
    }
    return 0;
}
