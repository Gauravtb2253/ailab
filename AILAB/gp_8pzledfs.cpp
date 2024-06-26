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

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

#define N 3

struct Node {
    Node* parent;
    int mat[N][N];
    int x, y;
    int level;
    string action; 
};

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent, string action) {
    Node* node = new Node;
    node->parent = parent;

    memcpy(node->mat, mat, sizeof node->mat);
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->level = level;
    node->x = newX;
    node->y = newY;
    node->action = action;

    return node;
}

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool isEqual(int mat1[N][N], int mat2[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (mat1[i][j] != mat2[i][j])
                return false;
    return true;
}

void printPath(Node* root) {
    if (root == NULL)
        return;
    printPath(root->parent);
    if (!root->action.empty()) {
        cout << "Action: " << root->action << endl;
    }
    printMatrix(root->mat);
    cout << "Depth: " << root->level << endl;
    cout << endl;
}

int row[] = {0, -1, 1, 0};
int col[] = {-1, 0, 0, 1};
string actions[] = {"Left", "Up", "Down", "Right"};

bool dfs(int final[N][N], Node* root, int depth) {
    if (isEqual(final, root->mat)) {
        printPath(root);
        return true;
    }
    if (depth <= 0) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        int newx = root->x + row[i];
        int newy = root->y + col[i];
        if (isSafe(newx, newy)) {
            Node* child = newNode(root->mat, root->x, root->y, newx, newy, root->level + 1, root, actions[i]);
            if (dfs(final, child, depth - 1)) {
                return true;
            }
        }
    }
    return false;
}

void solve(int initial[N][N], int x, int y, int final[N][N], int depth) {
    Node* root = newNode(initial, x, y, x, y, 0, NULL, "");
    if (!dfs(final, root, depth)) {
        cout << "Solution Doesn't Exist up to that level " << endl;
    }
}

int main() {
    int initial[N][N] =
    {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    int final[N][N] =
    {
        {1, 2, 3},
        {0, 5, 6},
        {7, 8, 4}
    };

    int x = 1, y = 2;
    int depth = 10;
    solve(initial, x, y, final, depth);

    return 0;
}
