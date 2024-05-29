#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
void printpath(map<p, p> parent, p u)     
{
    if (u.first == 0 && u.second == 0) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    printpath(parent, parent[u]);      
    cout << u.first << " " << u.second << endl; 
}

void BFS(int a, int b, int target)
{
    map<p, int> visited;
    bool isSolvable = false;
    map<p, p> parent;
    
    queue<p> q;   

    q.push(make_pair(0, 0));  
    while (!q.empty()) {

        auto u = q.front();
        // cout<<u.first<<" "<<u.second<<endl;
        q.pop();
        if (visited[u] == 1)
            continue;  

        if ((u.first > a || u.second > b || u.first < 0
            || u.second < 0))
            continue;                
        // cout<<u.first<<" "<<u.second<<endl;

        visited[{ u.first, u.second }] = 1;

        if (u.first == target || u.second == target) {
            isSolvable = true;

            printpath(parent, u);
            if (u.first == target) {
                if (u.second != 0)    
                    cout << u.first << " " << 0 << endl;
            }
            else {
                if (u.first != 0)
                    cout << 0 << " " << u.second << endl;
            }
            return;
        }

        //  fill the jug 2
        if (visited[{ u.first, b }] != 1) {
            q.push({ u.first, b });
            parent[{ u.first, b }] = u;
        }

        //  fill the jug 1
        if (visited[{ a, u.second }] != 1) {
            q.push({ a, u.second });
            parent[{ a, u.second }] = u;
        }

        // transfer jug 1 -> jug 2
        int d = b - u.second;
        if (u.first >= d) {
            int c = u.first - d;
            if (visited[{ c, b }] != 1) {
                q.push({ c, b });
                parent[{ c, b }] = u;
            }
        }
        else {
            int c =   u.first + u.second;
            if (visited[{ 0, c }] != 1) {
                q.push({ 0, c });
                parent[{ 0, c }] = u;
            }
        }
        // transfer jug 2 -> jug 1
        d = a - u.first;
        if (u.second >= d) {
            int c = u.second - d;
            if (visited[{ a, c }] != 1) {
                q.push({ a, c });
                parent[{ a, c }] = u;
            }
        }
        else {
            int c = u.first + u.second;
            if (visited[{ c, 0 }] != 1) {
                q.push({ c, 0 });
                parent[{ c, 0 }] = u;
            }
        }

        // empty the jug 2
        if (visited[{ u.first, 0 }] != 1) {
            q.push({ u.first, 0 });
            parent[{ u.first, 0 }] = u;
        }

        // empty the jug 1
        if (visited[{ 0, u.second }] != 1) {
            q.push({ 0, u.second });
            parent[{ 0, u.second }] = u;
        }
    }
    if (!isSolvable)
        cout << "No solution";
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
    BFS(Jug1, Jug2, target);
    return 0;
}

