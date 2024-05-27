// #include<bits/stdc++.h>
// using namespace std;

// const vector<vector<int>> GOAL_STATE = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 0}
// };

// int calculateHeuristic(const vector<vector<int>>& state) {
//     int heuristic = 0;
//     for (int i = 0; i < state.size(); i++) {
//         for (int j = 0; j < state[i].size(); j++) {
//             int value = state[i][j];
//             if (value != 0) {
//                 int targetX = (value - 1) / state.size();
//                 int targetY = (value - 1) % state.size();
//                 heuristic += abs((i - targetX)) + abs((j - targetY));
//             }
//         }
//     }
//     return heuristic;
// }

// class Node {
// public:
//     vector<vector<int>> state;
//     int heuristic;
//     int cost;
//     Node* parent;

//     Node(const vector<vector<int>>& state, Node* parent) : state(state), parent(parent) {
//         heuristic = calculateHeuristic(state);
//         cost = (parent != NULL) ? parent->cost + 1 : 0;
//     }
// };

// class CompareNode {
// public:
//     bool operator()(Node* a, Node* b) {
//         return (a->heuristic) > (b->heuristic);
//     }
// };

// Node* bestFirstSearch(const vector<vector<int>>& initial) {
//     priority_queue<Node*, vector<Node*>, CompareNode> queue;
//     unordered_set<string> visited;
//     Node* root = new Node(initial, NULL);
//     queue.push(root);

//     while (!queue.empty()) {
//         Node* current = queue.top();
//         queue.pop();

//         if (current->state == GOAL_STATE) {
//             return current;
//         }

//         visited.insert(to_string(current->state[0][0]) + to_string(current->state[0][1]) + to_string(current->state[0][2]) +
//                        to_string(current->state[1][0]) + to_string(current->state[1][1]) + to_string(current->state[1][2]) +
//                        to_string(current->state[2][0]) + to_string(current->state[2][1]) + to_string(current->state[2][2]));

//         int zeroX = 0, zeroY = 0;

//         for (zeroX = 0; zeroX < current->state.size(); zeroX++) {
//             for (zeroY = 0; zeroY < current->state[zeroX].size(); zeroY++) {
//                 if (current->state[zeroX][zeroY] == 0) {
//                     break;
//                 }
//             }
//             if (zeroY != current->state[zeroX].size()) {
//                 break;
//             }
//         }

//         int dx[] = {0, 0, -1, 1};
//         int dy[] = {-1, 1, 0, 0};
//         for (int i = 0; i < 4; i++) {
//             int newX = zeroX + dx[i];
//             int newY = zeroY + dy[i];
//             if (newX >= 0 && newX < (current->state.size()) && newY >= 0 && newY < (current->state[newX].size())) {
//                 vector<vector<int>> newState = current->state;
//                 newState[zeroX][zeroY] = current->state[newX][newY];
//                 newState[newX][newY] = 0;
//                 Node* child = new Node(newState, current);
//                 if (visited.find(to_string(child->state[0][0]) + to_string(child->state[0][1]) + to_string(child->state[0][2]) +
//                                  to_string(child->state[1][0]) + to_string(child->state[1][1]) + to_string(child->state[1][2]) +
//                                  to_string(child->state[2][0]) + to_string(child->state[2][1]) + to_string(child->state[2][2])) == visited.end()) {
//                     queue.push(child);
//                 }
//             }
//         }
//     }
//     return NULL;
// }

// void printSolution(Node* solution) {
//     vector<vector<vector<int>>> path;
//     while (solution != NULL) {
//         path.push_back(solution->state);
//         solution = solution->parent;
//     }
//     reverse(path.begin(), path.end());
//     for (const auto& state : path) {
//         for (const auto& row : state) {
//             for (int value : row) {
//                 cout << value << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
// }

// int main() {
//     vector<vector<int>> initial = {
//         {1, 2, 3},
//         {0, 4, 6},
//         {7, 5, 8}
//     };

//     cout << "Initial State:" << endl;
//     for (const auto& row : initial) {
//         for (int value : row) {
//             cout << value << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;

//     cout << "Goal State:" << endl;
//     for (const auto& row : GOAL_STATE) {
//         for (int value : row) {
//             cout << value << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;

//     Node* solution = bestFirstSearch(initial);

//     if (solution != NULL) {
//         cout << "Solution found:" << endl;
//         printSolution(solution);
//     } else {
//         cout << "No solution found." << endl;
//     }

//     return 0;
// }

//==========================================================================

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
};

class CompareNode
{
public:
    bool operator()(Node *a, Node *b)
    {
        return (a->heuristic) > (b->heuristic);
    }
};

Node *bestFirstSearch(const vector<vector<int>> &initial)
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

    Node *solution = bestFirstSearch(initial);

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

    int h = heuristics(board, goal);
    pq.push({h, board});

    while (!pq.empty())
    {
        vector<vector<int>> current = pq.top().second;
        pq.pop();

        depth++;
        printBoard(current);

        int x, y;
        findEmpty(current, x, y);
        
        if (isGoalState(current, goal))
        {
            cout << "Goal state reached" << endl;
            cout << "Depth: " << depth << endl;
            cout << "Cost: " << depth - 1 << endl;
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
                pq.push({h, current});
                swap(current[newX][newY], current[x][y]);
            }
        }
    }
    cout << "Goal state not reached" << endl;
    return;
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
    cout << "8 Puzzle Problem using Best First Search -"<< endl;
    cout << "Initial State - " << endl;
    findEmpty(initial, x, y);
    solve(initial, goal, 0, x, y);

    return 0;
}