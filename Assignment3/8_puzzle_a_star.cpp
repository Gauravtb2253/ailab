// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_set>
// #include <algorithm>
// #include <cmath>
// #include <functional>

// using namespace std;

// // Define the goal state of the 8-puzzle
// vector<vector<int>> goalState = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 0}
// };
// // Define a struct to represent the state of the puzzle
// struct PuzzleState
// {
//     vector<vector<int>> board;
//     int cost;            // Cost to reach this state from the initial state
//     int heuristic;       // Heuristic value (Manhattan distance)
//     PuzzleState *parent; // Pointer to the parent state

//     PuzzleState(vector<vector<int>> b, int c, int h, PuzzleState *p) : board(b), cost(c), heuristic(h), parent(p) {}

//     // Function to calculate the Manhattan distance heuristic
//     int calculateHeuristic()
//     {
//         int h = 0;
//         for (int i = 0; i < 3; ++i)
//         {
//             for (int j = 0; j < 3; ++j)
//             {
//                 if (board[i][j] != 0)
//                 {
//                     int goalX = (board[i][j] - 1) / 3;
//                     int goalY = (board[i][j] - 1) % 3;
//                     h += abs(i - goalX) + abs(j - goalY);
//                 }
//             }
//         }
//         return h;
//     }

//     // Function to check if this state is the goal state
//     bool isGoal()
//     {
//         return board == goalState;
//     }

//     // Function to generate possible next states
//     vector<PuzzleState *> getNextStates()
//     {
//         vector<PuzzleState *> nextStates;
//         int dx[] = {1, -1, 0, 0};
//         int dy[] = {0, 0, 1, -1};
//         int x, y;

//         // Find the position of the blank tile (0)
//         for (int i = 0; i < 3; ++i)
//         {
//             for (int j = 0; j < 3; ++j)
//             {
//                 if (board[i][j] == 0)
//                 {
//                     x = i;
//                     y = j;
//                     break;
//                 }
//             }
//         }

//         // Generate next states by moving tiles into the blank space
//         for (int i = 0; i < 4; ++i)
//         {
//             int newX = x + dx[i];
//             int newY = y + dy[i];
//             if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3)
//             {
//                 vector<vector<int>> newBoard = board;
//                 swap(newBoard[x][y], newBoard[newX][newY]);
//                 PuzzleState *nextState = new PuzzleState(newBoard, cost + 1, calculateHeuristic(), this);
//                 nextStates.push_back(nextState);
//             }
//         }

//         return nextStates;
//     }

//     bool operator==(const PuzzleState &other) const
//     {
//         return board == other.board;
//     }

//     struct Hash
//     {
//         size_t operator()(const PuzzleState *state) const
//         {
//             size_t hashVal = 0;
//             for (const auto &row : state->board)
//             {
//                 for (int val : row)
//                 {
//                     hashVal ^= hash<int>()(val) + 0x9e3779b9 + (hashVal << 6) + (hashVal >> 2);
//                 }
//             }
//             return hashVal;
//         }
//     };
// };

// // A* algorithm implementation
// vector<vector<vector<int>>> aStar(vector<vector<int>> initialState)
// {
//     PuzzleState *initial = new PuzzleState(initialState, 0, 0, nullptr);
//     initial->heuristic = initial->calculateHeuristic();

//     priority_queue<PuzzleState *, vector<PuzzleState *>, function<bool(PuzzleState *, PuzzleState *)>> frontier(
//         [](PuzzleState *a, PuzzleState *b)
//         {
//             return (a->cost + a->heuristic) > (b->cost + b->heuristic);
//         });

//     frontier.push(initial);

//     unordered_set<PuzzleState *, PuzzleState::Hash> visited;

//     while (!frontier.empty())
//     {
//         PuzzleState *current = frontier.top();
//         frontier.pop();

//         if (current->isGoal())
//         {
//             // Reconstruct the path
//             vector<vector<vector<int>>> path;
//             while (current != nullptr)
//             {
//                 path.push_back(current->board);
//                 current = current->parent;
//             }
//             reverse(path.begin(), path.end());
//             return path;
//         }

//         visited.insert(current);

//         // Generate next states
//         vector<PuzzleState *> nextStates = current->getNextStates();
//         for (PuzzleState *nextState : nextStates)
//         {
//             if (visited.find(nextState) == visited.end())
//             {
//                 frontier.push(nextState);
//             }
//         }
//     }

//     return {}; // No solution found
// }

// // Function to print the puzzle state
// void printPuzzle(const vector<vector<int>> &puzzle)
// {
//     for (int i = 0; i < 3; ++i)
//     {
//         for (int j = 0; j < 3; ++j)
//         {
//             cout << puzzle[i][j] << " ";
//         }
//         cout << endl; // Add newline after each row
//     }
//     cout << endl; // Add extra newline after the entire puzzle
// }

// int main()
// {
//     vector<vector<int>> initialState = {
//         {1, 2, 3},
//         {0, 4, 6},
//         {7, 5, 8}
//     };

//     cout << "Initial State:" << endl;
//     printPuzzle(initialState);

//     vector<vector<vector<int>>> finalState = aStar(initialState);

//     cout << "Solution Path:" << endl;
//     for (const auto &state : finalState)
//     {
//         printPuzzle(state);
//     }

//     return 0;
// }

//=================================================================================================

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <set>
// #include <algorithm>
// #include <cmath>
// #include <functional>

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> goalState = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 0}};

// int calculateHeuristic(const vector<vector<int>> &state)
// {
//     int heuristic = 0;
//     for (int i = 0; i < state.size(); i++)
//     {
//         for (int j = 0; j < state[i].size(); j++)
//         {
//             int value = state[i][j];
//             if (value != 0)
//             {
//                 int targetX = (value - 1) / state.size();
//                 int targetY = (value - 1) % state.size();
//                 heuristic += abs(static_cast<int>(i - targetX)) + abs(static_cast<int>(j - targetY));
//             }
//         }
//     }
//     return heuristic;
// }

// class Node
// {
// public:
//     vector<vector<int>> state;
//     int heuristic;
//     int cost;
//     Node *parent;

//     Node(const vector<vector<int>> &state, Node *parent) : state(state), parent(parent)
//     {
//         heuristic = calculateHeuristic(state);
//         cost = (parent != NULL) ? parent->cost + 1 : 0;
//     }

//     bool isGoal() const
//     {
//         return state == goalState;
//     }

//     vector<Node *> getNextStates()
//     {
//         vector<Node *> nextStates;
//         int dx[] = {1, -1, 0, 0};
//         int dy[] = {0, 0, 1, -1};
//         int x, y;

//         for (int i = 0; i < 3; ++i)
//         {
//             for (int j = 0; j < 3; ++j)
//             {
//                 if (state[i][j] == 0)
//                 {
//                     x = i;
//                     y = j;
//                     break;
//                 }
//             }
//         }

//         for (int i = 0; i < 4; ++i)
//         {
//             int newX = x + dx[i];
//             int newY = y + dy[i];
//             if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3)
//             {
//                 vector<vector<int>> newBoard = state;
//                 swap(newBoard[x][y], newBoard[newX][newY]);
//                 Node *nextState = new Node(newBoard, this);
//                 nextStates.push_back(nextState);
//             }
//         }

//         return nextStates;
//     }

//     bool operator==(const Node &other) const
//     {
//         return state == other.state;
//     }
// };

// class CompareNode
// {
// public:
//     bool operator()(Node *a, Node *b)
//     {
//         return (a->heuristic) > (b->heuristic);
//     }
// };

// vector<vector<vector<int>>> aStar(vector<vector<int>> initialState)
// {
//     Node *initial = new Node(initialState, nullptr);

//     priority_queue<Node *, vector<Node *>, CompareNode> frontier;

//     frontier.push(initial);

//     set<Node *> visited;

//     while (!frontier.empty())
//     {
//         Node *current = frontier.top();
//         frontier.pop();

//         if (current->isGoal())
//         {
//             vector<vector<vector<int>>> path;
//             while (current != nullptr)
//             {
//                 path.push_back(current->state);
//                 current = current->parent;
//             }
//             reverse(path.begin(), path.end());
//             return path;
//         }

//         visited.insert(current);

//         vector<Node *> nextStates = current->getNextStates();
//         for (Node *nextState : nextStates)
//         {
//             if (visited.find(nextState) == visited.end())
//             {
//                 frontier.push(nextState);
//             }
//         }
//     }

//     return {};
// }

// void printPuzzle(const vector<vector<int>> &puzzle)
// {
//     for (int i = 0; i < 3; ++i)
//     {
//         for (int j = 0; j < 3; ++j)
//         {
//             cout << puzzle[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// int main()
// {
//     vector<vector<int>> initialState = {
//         {1, 2, 3},
//         {0, 4, 6},
//         {7, 5, 8}};

//     cout << "Initial State:" << endl;
//     printPuzzle(initialState);

//     cout << "Goal State:" << endl;
//     printPuzzle(goalState);

//     vector<vector<vector<int>>> finalState = aStar(initialState);

//     cout << "Solution Path:" << endl;
//     for (const auto &state : finalState)
//     {
//         printPuzzle(state);
//     }

//     return 0;
// }

//==============================================================================================

/*
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> goalState = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}};

int calculateHeuristic(const vector<vector<int>> &state)
{
    int heuristic = 0;
    for (int i = 0; i < state.size(); i++)
    {
        for (int j = 0; j < state[i].size(); j++)
        {
            int value = state[i][j];
            if (value != 0)
            {
                int targetX = (value - 1) / state.size();
                int targetY = (value - 1) % state.size();
                heuristic += abs(i - targetX) + abs(j - targetY);
            }
        }
    }
    return heuristic;
}

class Node
{
public:
    vector<vector<int>> state;
    int heuristic;
    int cost;
    Node *parent;

    Node(const vector<vector<int>> &state, Node *parent) : state(state), parent(parent)
    {
        heuristic = calculateHeuristic(state);
        cost = (parent != nullptr) ? parent->cost + 1 : 0;
    }

    bool isGoal() const
    {
        return state == goalState;
    }

    vector<Node *> getNextStates()
    {
        vector<Node *> nextStates;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int blankX, blankY;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (state[i][j] == 0)
                {
                    blankX = i;
                    blankY = j;
                    break;
                }
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            int newX = blankX + dx[i];
            int newY = blankY + dy[i];
            if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3)
            {
                vector<vector<int>> newBoard = state;
                swap(newBoard[blankX][blankY], newBoard[newX][newY]);
                Node *nextState = new Node(newBoard, this);
                nextStates.push_back(nextState);
            }
        }

        return nextStates;
    }

    bool operator==(const Node &other) const
    {
        return state == other.state;
    }
};

class CompareNode
{
public:
    bool operator()(Node *a, Node *b)
    {
        return (a->heuristic) > (b->heuristic);
    }
};

vector<vector<vector<int>>> aStar(vector<vector<int>> initialState)
{
    Node *initial = new Node(initialState, nullptr);

    priority_queue<Node *, vector<Node *>, CompareNode> frontier;

    frontier.push(initial);

    set<Node *> visited;

    while (!frontier.empty())
    {
        Node *current = frontier.top();
        frontier.pop();

        if (current->isGoal())
        {
            vector<vector<vector<int>>> path;
            while (current != nullptr)
            {
                path.push_back(current->state);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        visited.insert(current);

        vector<Node *> nextStates = current->getNextStates();
        for (Node *nextState : nextStates)
        {
            if (visited.find(nextState) == visited.end())
            {
                frontier.push(nextState);
            }
        }
    }

    return {};
}

void printPuzzle(const vector<vector<int>> &puzzle)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> initialState = {
        {1, 2, 3},
        {0, 4, 6},
        {7, 5, 8}};

    cout << "Initial State:" << endl;
    printPuzzle(initialState);

    cout << "Goal State:" << endl;
    printPuzzle(goalState);

    vector<vector<vector<int>>> finalState = aStar(initialState);

    cout << "Solution Path:" << endl;
    for (const auto &state : finalState)
    {
        printPuzzle(state);
    }

    return 0;
}

*/
/*
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

// Define the goal state of the 8-puzzle
vector<vector<int>> goalState = {
    {1, 2, 3},
    {8, 0, 4},
    {7, 6, 5}};

// Define a class to represent the state of the puzzle
class PuzzleState
{
public:
    vector<vector<int>> board;
    int cost;            // Cost to reach this state from the initial state
    int heuristic;       // Heuristic value (Manhattan distance)
    PuzzleState *parent; // Pointer to the parent state

    PuzzleState(vector<vector<int>> b, int c, int h, PuzzleState *p) : board(b), cost(c), heuristic(h), parent(p) {}

    // Function to calculate the Manhattan distance heuristic
    int calculateHeuristic()
    {
        int h = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] != 0)
                {
                    int goalX = (board[i][j] - 1) / 3;
                    int goalY = (board[i][j] - 1) % 3;
                    h += abs(i - goalX) + abs(j - goalY);
                }
            }
        }
        return h;
    }

    // Function to check if this state is the goal state
    bool isGoal()
    {
        return board == goalState;
    }

    // Function to generate possible next states
    vector<PuzzleState *> getNextStates()
    {
        vector<PuzzleState *> nextStates;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int x, y;

        // Find the position of the blank tile (0)
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == 0)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        // Generate next states by moving tiles into the blank space
        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3)
            {
                vector<vector<int>> newBoard = board;
                swap(newBoard[x][y], newBoard[newX][newY]);
                PuzzleState *nextState = new PuzzleState(newBoard, cost + 1, calculateHeuristic(), this);
                nextStates.push_back(nextState);
            }
        }

        return nextStates;
    }

    bool operator==(const PuzzleState &other) const
    {
        return board == other.board;
    }

    class Hash
    {
    public:
        size_t operator()(const PuzzleState *state) const
        {
            size_t hashVal = 0;
            for (const auto &row : state->board)
            {
                for (int val : row)
                {
                    hashVal ^= hash<int>()(val) + 0x9e3779b9 + (hashVal << 6) + (hashVal >> 2);
                }
            }
            return hashVal;
        }
    };
};

// A* algorithm implementation
vector<vector<vector<int>>> aStar(vector<vector<int>> initialState)
{
    PuzzleState *initial = new PuzzleState(initialState, 0, 0, nullptr);
    initial->heuristic = initial->calculateHeuristic();

    priority_queue<PuzzleState *, vector<PuzzleState *>, function<bool(PuzzleState *, PuzzleState *)>> frontier(
        [](PuzzleState *a, PuzzleState *b)
        {
            return (a->cost + a->heuristic) > (b->cost + b->heuristic);
        });

    frontier.push(initial);

    unordered_set<PuzzleState *, PuzzleState::Hash> visited;

    while (!frontier.empty())
    {
        PuzzleState *current = frontier.top();
        frontier.pop();

        if (current->isGoal())
        {
            // Reconstruct the path
            vector<vector<vector<int>>> path;
            while (current != nullptr)
            {
                path.push_back(current->board);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        visited.insert(current);

        // Generate next states
        vector<PuzzleState *> nextStates = current->getNextStates();
        for (PuzzleState *nextState : nextStates)
        {
            if (visited.find(nextState) == visited.end())
            {
                frontier.push(nextState);
            }
        }
    }

    return {}; // No solution found
}

// Function to print the puzzle state
void printPuzzle(const vector<vector<int>> &puzzle)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << puzzle[i][j] << " ";
        }
        cout << endl; // Add newline after each row
    }
    cout << endl; // Add extra newline after the entire puzzle
}

int main()
{
    vector<vector<int>> initialState = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 0, 5}};

    cout << "Initial State:" << endl;
    printPuzzle(initialState);

    vector<vector<vector<int>>> finalState = aStar(initialState);

    cout << "Solution Path:" << endl;
    for (const auto &state : finalState)
    {
        printPuzzle(state);
    }

    return 0;
}

*/

/*
#include <bits/stdc++.h>
using namespace std;

const vector<vector<int>> goalstate = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}};

int calculateHeuristic(const vector<vector<int>> &state)
{
    int heuristic = 0;
    for (int i = 0; i < state.size(); i++)
    {
        for (int j = 0; j < state[i].size(); j++)
        {
            int value = state[i][j];
            if (value != 0)
            {
                int targetX = (value - 1) / state.size();
                int targetY = (value - 1) % state.size();
                heuristic += abs((i - targetX)) + abs((j - targetY));
            }
        }
    }
    return heuristic;
}

class Node
{
public:
    vector<vector<int>> state;
    int heuristic;
    int cost;
    Node *parent;

    Node(const vector<vector<int>> &state, Node *parent) : state(state), parent(parent)
    {
        heuristic = calculateHeuristic(state);
        cost = (parent != NULL) ? parent->cost + 1 : 0;
    }

    int getTotalCost() const
    {
        return cost + heuristic;
    }
};

class CompareNode
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->getTotalCost() > b->getTotalCost();
    }
};

Node *aStarSearch(const vector<vector<int>> &initial)
{
    priority_queue<Node *, vector<Node *>, CompareNode> frontier;
    set<Node *> visited;
    Node *root = new Node(initial, NULL);
    frontier.push(root);

    while (!frontier.empty())
    {
        Node *current = frontier.top();
        frontier.pop();

        if (current->state == goalstate)
        {
            return current;
        }

        visited.insert(current);

        int zeroX = 0, zeroY = 0;

        for (zeroX = 0; zeroX < current->state.size(); zeroX++)
        {
            for (zeroY = 0; zeroY < current->state[zeroX].size(); zeroY++)
            {
                if (current->state[zeroX][zeroY] == 0)
                {
                    break;
                }
            }
            if (zeroY != current->state[zeroX].size())
            {
                break;
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int newX = zeroX + dx[i];
            int newY = zeroY + dy[i];
            if (newX >= 0 && newX < (current->state.size()) && newY >= 0 && newY < (current->state[newX].size()))
            {
                vector<vector<int>> newState = current->state;
                newState[zeroX][zeroY] = current->state[newX][newY];
                newState[newX][newY] = 0;
                Node *child = new Node(newState, current);
                if (visited.find(child) == visited.end())
                {
                    frontier.push(child);
                }
            }
        }
    }
    return NULL;
}

void printSolution(Node *solution)
{
    vector<vector<vector<int>>> path;
    while (solution != NULL)
    {
        path.push_back(solution->state);
        solution = solution->parent;
    }
    reverse(path.begin(), path.end());
    for (const auto &state : path)
    {
        for (const auto &row : state)
        {
            for (int value : row)
            {
                cout << value << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> initial = {
        {1, 2, 3},
        {0, 4, 6},
        {7, 5, 8}};

    cout << "Initial State:" << endl;
    for (const auto &row : initial)
    {
        for (int value : row)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Goal State:" << endl;
    for (const auto &row : goalstate)
    {
        for (int value : row)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;

    Node *solution = aStarSearch(initial);

    if (solution != NULL)
    {
        cout << "Solution found:" << endl;
        printSolution(solution);
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}


*/

#include <bits/stdc++.h>
#include <vector>
#include <queue>
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
    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>,
                   greater<pair<int, vector<vector<int>>>>> pq;
    int g = depth;
    int h = heuristics(board, goal);
    pq.push({(g+h), board});

    while (!pq.empty())
    {
        vector<vector<int>> current = pq.top().second;
        pq.pop();

        depth++;
        g = depth;
        printBoard(current);

        int x, y;
        findEmpty(current, x, y);
        
        if (isGoalState(current, goal))
        {
            cout << "Goal state reached" << endl;
            cout << "Depth : " << depth << endl;
            cout << "Cost : " << depth-1;

            return;
        }

        // right, left, up, down
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < current.size() && newY >= 0 && newY < current.size())
            {
                swap(current[x][y], current[newX][newY]);
                h = heuristics(current, goal);
                pq.push({(h+g), current});
                swap(current[newX][newY], current[x][y]);
            }
        }
        // depth++;

    }
    cout << "Goal state not reached" << endl;
    return; 
}

int main()
{
    vector<vector<int>> initial = { {1, 2, 3},
                                    {0, 4, 6},
                                    {7, 5, 8}};

    vector<vector<int>> goal = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 0}};
    int x, y;
    cout << "Initial State - " << endl;
    findEmpty(initial, x, y);
    solve(initial, goal, 0, x, y);

    return 0;
}