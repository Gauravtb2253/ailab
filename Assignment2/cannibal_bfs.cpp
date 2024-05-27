#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct state
{
    int miss_left;
    int miss_right;
    int cann_left;
    int cann_right;
    int boat; // 0 for left, 1 for right
    vector<state> path; // Path to reach this state
};

bool isVisited(state curr, vector<state> &visited)
{
    int n = visited.size();
    for (int i = 0; i < n; i++)
    {
        if (visited[i].boat == curr.boat &&
            visited[i].miss_left == curr.miss_left &&
            visited[i].cann_left == curr.cann_left &&
            visited[i].cann_right == curr.cann_right)
        {
            return true;
        }
    }
    return false;
}

bool isGoal(state curr)
{
    return curr.miss_left == 0 && curr.cann_left == 0;
}

bool isValid(state curr)
{
    if (curr.miss_left < 0 || curr.miss_left > 3 || curr.miss_right < 0 || curr.miss_right > 3 ||
        curr.cann_left < 0 || curr.cann_left > 3 || curr.cann_right < 0 || curr.cann_right > 3)
        return false;
    if ((curr.cann_left > curr.miss_left && curr.miss_left != 0) ||
        (curr.cann_right > curr.miss_right && curr.miss_right != 0))
        return false;
    return true;
}

void printState(state curr)
{
    cout << "Left Bank -> ";
    cout << curr.miss_left << " Missionaries, " << curr.cann_left << " Cannibals, Boat: ";
    cout << "Right Bank -> ";
    cout << curr.miss_right << " Missionaries, " << curr.cann_right << " Cannibals" << endl;
}

void printPath(state curr)
{
    for (const state& s : curr.path)
    {
        printState(s);
    }
    // printState(curr);
}

void solve(state initial_state)
{
    vector<state> visited;
    initial_state.path.push_back(initial_state); // Add initial state to the path
    visited.push_back(initial_state);

    queue<state> q;
    q.push(initial_state);

    while (!q.empty())
    {
        state temp = q.front();
        q.pop();

        if (isGoal(temp))
        {
            printPath(temp);
            continue;
        }

        for (int m = 0; m <= 2; m++)
        {
            for (int c = 0; c <= 2; c++)
            {
                if (m + c <= 2 && m + c > 0)
                {
                    state next = temp;
                    if (temp.boat == 0)
                    {
                        next.cann_left -= c;
                        next.cann_right += c;
                        next.miss_left -= m;
                        next.miss_right += m;
                        next.boat = 1;
                    }
                    else
                    {
                        next.cann_left += c;
                        next.cann_right -= c;
                        next.miss_left += m;
                        next.miss_right -= m;
                        next.boat = 0;
                    }

                    if (isValid(next) && !isVisited(next, visited))
                    {
                        next.path.push_back(next); // Add the current state to the path
                        q.push(next);
                        visited.push_back(next);
                    }
                }
            }
        }
    }
}

int main()
{
    state initial_state = {3, 0, 3, 0, 0};
    solve(initial_state);
    return 0;
}
