// /*

// #include <iostream>
// #include <stack>
// #include <unordered_set>
// #include <vector>
// using namespace std;

// struct State {
//     vector<vector<int>> board;
//     int zeroRow, zeroCol;

//     State(vector<vector<int>> b, int zr, int zc) : board(b), zeroRow(zr), zeroCol(zc) {}

//     bool operator==(const State& other) const {
//         return board == other.board;
//     }

//     size_t hash() const {
//         size_t res = 0;
//         for (const auto& row : board) {
//             for (int val : row) {
//                 res = res * 10 + val;
//             }
//         }
//         return res;
//     }
// };

// namespace std {
//     template <>
//     struct hash<State> {
//         size_t operator()(const State& s) const {
//             return s.hash();
//         }
//     };
// }

// bool isGoalState(const State& s) {
//     vector<vector<int>> goalBoard = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
//     return s.board == goalBoard;
// }

// vector<State> getNeighbors(const State& s) {
//     vector<State> neighbors;
//     static const int dr[] = {-1, 1, 0, 0};
//     static const int dc[] = {0, 0, -1, 1};
//     for (int d = 0; d < 4; ++d) {
//         int newZeroRow = s.zeroRow + dr[d];
//         int newZeroCol = s.zeroCol + dc[d];
//         if (newZeroRow >= 0 && newZeroRow < 3 && newZeroCol >= 0 && newZeroCol < 3) {
//             vector<vector<int>> newBoard = s.board;
//             swap(newBoard[s.zeroRow][s.zeroCol], newBoard[newZeroRow][newZeroCol]);
//             neighbors.emplace_back(newBoard, newZeroRow, newZeroCol);
//         }
//     }
//     return neighbors;
// }

// void printBoard(const vector<vector<int>>& board) {
//     for (const auto& row : board) {
//         for (int val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// void printSolution(const vector<State>& path) {
//     cout << "Initial state:" << endl;
//     printBoard(path.front().board);

//     for (size_t i = 1; i < path.size(); ++i) {
//         cout << "Step " << i << ":" << endl;
//         printBoard(path[i].board);
//     }

//     cout << "Final state:" << endl;
//     printBoard(path.back().board);
// }

// vector<State> solvePuzzleDFS(const State& startState) {
//     stack<vector<State>> s;
//     s.push({startState});
//     unordered_set<State> visited;
//     visited.insert(startState);

//     while (!s.empty()) {
//         vector<State> path = s.top();
//         s.pop();
//         State currentState = path.back();

//         if (isGoalState(currentState)) {
//             return path;
//         }

//         for (const State& neighbor : getNeighbors(currentState)) {
//             if (visited.find(neighbor) == visited.end()) {
//                 visited.insert(neighbor);
//                 vector<State> newPath = path;
//                 newPath.push_back(neighbor);
//                 s.push(newPath);
//             }
//         }
//     }

//     return {}; // No solution found
// }

// int main() {
//     vector<vector<int>> initialBoard = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}};
//     State initialState(initialBoard, 2, 1);

//     vector<State> solution = solvePuzzleDFS(initialState);

//     if (!solution.empty()) {
//         cout << "Solution found!" << endl;
//         printSolution(solution);
//     } else {
//         cout << "No solution found." << endl;
//     }

//     return 0;
// }


// */

// #include <iostream>
// #include <stack>
// #include <set>
// #include <vector>
// using namespace std;

// struct State
// {
//     vector<vector<int>> board;
//     int zeroRow, zeroCol;

//     State(vector<vector<int>> b, int zr, int zc)
//     {
//         this->board = b;
//         this->zeroRow = zr;
//         this->zeroCol = zc;
//     }
// };

// bool isGoalState(State &s)
// {
//     vector<vector<int>> goalBoard = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
//     // vector<vector<int>> goalBoard = {{1, 2, 3}, {5, 8, 6}, {0, 7, 4}};
//     return s.board == goalBoard;
// }

// vector<State> getNeighbors(State &s)
// {
//     vector<State> neighbors;
//     vector<int> dr = {-1, 1, 0, 0};
//     vector<int> dc = {0, 0, -1, 1};
//     for (int d = 0; d < 4; d++)
//     {
//         int newZeroRow = s.zeroRow + dr[d];
//         int newZeroCol = s.zeroCol + dc[d];
//         if (newZeroRow >= 0 && newZeroRow < 3 && newZeroCol >= 0 && newZeroCol < 3)
//         {
//             vector<vector<int>> newBoard = s.board;
//             swap(newBoard[s.zeroRow][s.zeroCol], newBoard[newZeroRow][newZeroCol]);
//             neighbors.push_back({newBoard, newZeroRow, newZeroCol});
//         }
//     }
//     return neighbors;
// }

// void printBoard(vector<vector<int>> &board)
// {
//     for (const auto &row : board)
//     {
//         for (int val : row)
//         {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// void printSolution(vector<State> &path)
// {
//     for (int i = 1; i < path.size() - 1; i++)
//     {
//         cout << "Step " << i << ":" << endl;
//         printBoard(path[i].board);
//     }
// }

// int moves = 1;

// vector<State> solvePuzzleDFS(State &startState)
// {
//     stack<vector<State>> s;
//     s.push({startState});
//     set<vector<vector<int>>> visited;
//     visited.insert(startState.board);

//     while (!s.empty())
//     {
//         vector<State> path = s.top();
//         s.pop();

//         State currentState = path.back();

//         if (isGoalState(currentState))
//         {
//             for (State state : path)
//             {
//                 cout << "Move " << moves++ << ":" << endl;
//                 printBoard(state.board);
//             }
//             return path;
//         }

//         for (State neighbor : getNeighbors(currentState))
//         {
//             bool found = false;
//             if (visited.find(neighbor.board) != visited.end())
//             {
//                 found = true;
//             }
//             if (!found)
//             {
//                 visited.insert(neighbor.board);
//                 vector<State> newPath = path;
//                 newPath.push_back(neighbor);
//                 s.push(newPath);
//             }
//         }
//     }

//     return {};
// }

// int main()
// {
//     vector<vector<int>> initialBoard = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}};
//     State initialState(initialBoard, 2, 1);

//     // vector<vector<int>> initialBoard = {{1, 2, 3}, {5, 6, 0}, {7, 8, 4}};
//     // State initialState(initialBoard, 1, 2);

//     vector<State> solution = solvePuzzleDFS(initialState);

//     if (!solution.empty())
//     {
//         cout << "Solution found!" << endl;
//     }
//     else
//     {
//         cout << "No solution found." << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class State
{
public:
    vector<vector<int>> board;
    int zeroRow, zeroCol;
    State *parent;
    int level;

    State(vector<vector<int>> &b, int zr, int zc, State *p = nullptr, int l = 0)
    {
        board = b;
        zeroRow = zr;
        zeroCol = zc;
        parent = p;
        level = l;
    }

    vector<vector<int>> getBoard()
    {
        return board;
    }

    State move(int newX, int newY)
    {
        vector<vector<int>> newBoard = board;
        swap(newBoard[zeroRow][zeroCol], newBoard[newX][newY]);
        return State(newBoard, newX, newY, this, level + 1);
    }
};

bool operator<(const State &lhs, const State &rhs)
{
    return lhs.board < rhs.board;
}

void printMatrix(vector<vector<int>> &mat)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int x, int y)
{
    return (x >= 0 && x < 3 && y >= 0 && y < 3);
}

void printPath(State &root)
{
    if (root.parent == nullptr)
        return;
    printPath(*root.parent);
    cout << "Move " << root.level << ":" << endl;
    printMatrix(root.board);
}

bool solveDFS(State &node, State &final, set<State> &visited)
{
    visited.insert(node);

    if (node.board == final.board)
    {
        printPath(node);
        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        int newX = node.zeroRow + (i == 0) - (i == 2);
        int newY = node.zeroCol + (i == 1) - (i == 3);
        if (isSafe(newX, newY))
        {
            State childState = node.move(newX, newY);
            if (visited.find(childState) == visited.end())
            {
                if (solveDFS(childState, final, visited))
                    return true;
            }
        }
    }

    return false;
}

void solve(vector<vector<int>> &initial, int x, int y, vector<vector<int>> &final)
{
    State root(initial, x, y);
    State finalState(final, 2, 2);

    set<State> visited;
    if (solveDFS(root, finalState, visited))
        cout << "Solution found!" << endl;
    else
        cout << "No solution found." << endl;
}

int main()
{
    vector<vector<int>> initial = {{1, 2, 3}, {5, 6, 0}, {7, 8, 4}};
    vector<vector<int>> final = {{1, 2, 3}, {5, 8, 6}, {0, 7, 4}};

    int x = 1, y = 2;

    solve(initial, x, y, final);

    return 0;
}
