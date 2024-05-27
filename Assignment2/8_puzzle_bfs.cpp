#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class State
{
private:
    vector<vector<int>> board;
    int zeroRow, zeroCol;

public:
    State(vector<vector<int>> &b, int zr, int zc)
    {
        this->board = b;
        this->zeroRow = zr;
        this->zeroCol = zc;
    }

    vector<vector<int>> getBoard()
    {
        return board;
    }

    int getZeroRow()
    {
        return zeroRow;
    }

    int getZeroCol()
    {  
        return zeroCol;
    }
};

bool isGoalState(State &s)
{
    vector<vector<int>> goalBoard = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
    // vector<vector<int>> goalBoard = {{1, 2, 3}, {5, 8, 6}, {0, 7, 4}};
    return s.getBoard() == goalBoard;
}

vector<State> getNeighbors(State &s)
{
    vector<State> neighbors;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++)
    {
        int newZeroRow = s.getZeroRow() + dr[i];
        int newZeroCol = s.getZeroCol() + dc[i];
        if (newZeroRow >= 0 && newZeroRow < 3 && newZeroCol >= 0 && newZeroCol < 3)
        {
            vector<vector<int>> newBoard = s.getBoard();
            swap(newBoard[s.getZeroRow()][s.getZeroCol()], newBoard[newZeroRow][newZeroCol]);
            neighbors.push_back({newBoard, newZeroRow, newZeroCol});
        }
    }
    return neighbors;
}

void printBoard(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int moves = 1;

vector<State> solvePuzzleBFS(State &startState)
{
    queue<vector<State>> q;
    q.push({startState});
    set<vector<vector<int>>> visited;
    visited.insert(startState.getBoard());

    while (!q.empty())
    {
        vector<State> path = q.front();
        q.pop();

        State currentState = path.back();

        if (isGoalState(currentState))
        {
            for (State state : path)
            {
                cout << "Move " << moves++ << ":" << endl;
                printBoard(state.getBoard());
            }
            return path;
        }

        for (State neighbor : getNeighbors(currentState))
        {
            if (visited.find(neighbor.getBoard()) == visited.end())
            {
                visited.insert(neighbor.getBoard());
                vector<State> newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }

    return {};
}

int main()
{
    vector<vector<int>> initialBoard = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}};
    State initialState(initialBoard, 2, 1);

    // vector<vector<int>> initialBoard = {{1, 2, 3}, {5, 6, 0}, {7, 8, 4}};
    // State initialState(initialBoard, 1, 2);

    vector<State> solution = solvePuzzleBFS(initialState);
    
    if (!solution.empty())
    {
        cout << "Solution found!" << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
