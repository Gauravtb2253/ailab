#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

void printpath(map<p, p> parent, p u)
{
    if (u.first == 0 && u.second == 0)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    printpath(parent, parent[u]);
    cout << u.first << " " << u.second << endl;
}

void DFS(int a, int b, int target, map<p, int> &visited, map<p, p> &parent, bool &isSolvable, p u)
{
    if (isSolvable)
        return;

    if (u.first > a || u.second > b || u.first < 0 || u.second < 0)
        return;

    if (visited[u] == 1)
        return; 

    visited[u] = 1;

    if (u.first == target || u.second == target)
    {
        isSolvable = true;
        printpath(parent, u);

        if (u.first == target)
        {            
            // if (u.second != 0)
                cout << u.first << " " << 0 << endl;
        }
        else
        {
            // if (u.first != 0)
                cout << 0 << " " << u.second << endl;
        }
        return;
    }

    // Recursive calls for all possible moves

    //  fill the jug 2
    if (visited[{u.first, b}] != 1)
    {              
        parent[{u.first, b}] = u;
        DFS(a, b, target, visited, parent, isSolvable, {u.first, b});
    }

    //  fill the jug 1
    if (visited[{a, u.second}] != 1)
    {
        parent[{a, u.second}] = u;
        DFS(a, b, target, visited, parent, isSolvable, {a, u.second});
    }

    // transfer jug 1 -> jug 2
    int d = b - u.second;
    if (u.first >= d)
    {
        int c = u.first - d;
        if (visited[{c, b}] != 1)
        {
            parent[{c, b}] = u;
            DFS(a, b, target, visited, parent, isSolvable, {c, b});
        }
    }
    else
    {
        int c = u.first + u.second;
        if (visited[{0, c}] != 1)
        {
            parent[{0, c}] = u;
            DFS(a, b, target, visited, parent, isSolvable, {0, c});
        }
    }

    // transfer jug 2 -> jug 1
    d = a - u.first;
    if (u.second >= d)
    {
        int c = u.second - d;
        if (visited[{a, c}] != 1)
        {
            parent[{a, c}] = u;
            DFS(a, b, target, visited, parent, isSolvable, {a, c});
        }
    }
    else
    {
        int c = u.first + u.second;
        if (visited[{c, 0}] != 1)
        {
            parent[{c, 0}] = u;
            DFS(a, b, target, visited, parent, isSolvable, {c, 0});
        }
    }

    // empty the jug 2
    if (visited[{u.first, 0}] != 1)
    {
        parent[{u.first, 0}] = u;
        DFS(a, b, target, visited, parent, isSolvable, {u.first, 0});
    }

    // empty the jug 1
    if (visited[{0, u.second}] != 1)
    {
        parent[{0, u.second}] = u;
        DFS(a, b, target, visited, parent, isSolvable, {0, u.second});
    }
}

int main()
{
    int Jug1, Jug2, target;
    cout<<"Enter the jug1 size:"<<endl;
    cin>>Jug1;
    cout<<"Enter the jug2 size:"<<endl;
    cin>>Jug2;
    cout<<"Enter the target size:"<<endl;
    cin>>target;
    cout << "Path from initial state "
            "to solution state ::\n";

    map<p, int> visited;
    bool isSolvable = false;
    map<p, p> parent;

    DFS(Jug1, Jug2, target, visited, parent, isSolvable, {0, 0});

    if (!isSolvable)
        cout << "No solution";

    return 0;
}
