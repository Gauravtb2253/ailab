#include <iostream>
#include <vector>
using namespace std;

void findEmpty(vector<vector<int>> board, int &x, int &y)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == 0)
            {
                x = i;
                y = j;
                return;
            }
        }
    }
}

bool isGoalState(vector<vector<int>> &board, vector<vector<int>> &goal)
{
    return board == goal;
}

int heuristics(vector<vector<int>> &board, vector<vector<int>> &goal)
{
    int h = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] != goal[i][j])
            {
                h++;
            }
        }
    }
    return h;
}

void printBoard(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<int>> &board, vector<vector<int>> &goal, int depth, int x, int y)
{
    int h = heuristics(board, goal);

    while (true)
    {
        printBoard(board);

        if (isGoalState(board, goal))
        {
            cout << "Goal state reached" << endl;
            cout << "Depth: " << depth << endl;
            cout << "Cost: " << depth - 1 << endl;
            return;
        }

        // right, left, up, down
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        int newX = -1, newY = -1;
        int minH = h;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size())
            {
                swap(board[x][y], board[nx][ny]);
                int newH = heuristics(board, goal);
                if (newH < minH)
                {
                    minH = newH;
                    newX = nx;
                    newY = ny;
                }
                swap(board[nx][ny], board[x][y]);
            }
        }

        if (minH >= h)
        {
            cout << "Goal state not reached" << endl;
            return;
        }

        swap(board[x][y], board[newX][newY]);
        x = newX;
        y = newY;
        h = minH;
        depth++;
    }
}

int main()
{
    vector<vector<int>> initial = {{2, 8, 3},
                                    {1, 6, 4},
                                    {7, 0, 5}};

    vector<vector<int>> goal = {{1, 2, 3},
                                 {8, 0, 4},
                                 {7, 6, 5}};
    int x, y;
    cout << "8 Puzzle Problem using Hill Climbing -" << endl;
    cout << "Initial State - " << endl;
    findEmpty(initial, x, y);
    solve(initial, goal, 0, x, y);

    return 0;
}