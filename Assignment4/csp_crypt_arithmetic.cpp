#include <bits/stdc++.h>
using namespace std;

bool solved = false;

void solve(vector<char> letters, vector<int> values, vector<bool> &visited, vector<string> words)
{
    if (letters.size() == values.size())
    {
        map<char, int> m;
        for (int i = 0; i < letters.size(); i++)
        {
            m[letters[i]] = values[i];
        }
        if (m[words[0][0]] == 0 || m[words[1][0]] == 0 || m[words[2][0]] == 0)
        {
            return;
        }
        string word1 = "", word2 = "", res = "";
        for (char c : words[0])
        {
            word1 += to_string(m[c]);
        }
        for (char c : words[1])
        {
            word2 += to_string(m[c]);
        }
        for (char c : words[2])
        {
            res += to_string(m[c]);
        }
        if ((stoi(word1) + stoi(word2)) == stoi(res))
        {
            cout << endl;
            cout << "Solution:" << endl;
            for (auto it = m.begin(); it != m.end(); it++)
            {
                cout << it->first << " -> " << it->second << endl;
            }
            cout << endl;
            solved = true;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            values.push_back(i);
            solve(letters, values, visited, words);
            values.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    string word1 = "", word2 = "", result = "";
    cout << "Enter word1:" << endl;
    cin >> word1;
    cout << "Enter word2:" << endl;
    cin >> word2;
    cout << "Enter result:" << endl;
    cin >> result;

    if (result.length() > max(word1.length(), word2.length()) + 1)
    {
        cout << "No solution found." << endl;
    }
    else
    {
        unordered_set<char> set;
        for (char c : word1)
        {
            set.insert(c);
        }
        for (char c : word2)
        {
            set.insert(c);
        }
        for (char c : result)
        {
            set.insert(c);
        }
        if (set.size() > 10)
        {
            cout << "No solution found." << endl;
        }
        else
        {
            vector<char> letters(set.begin(), set.end());
            vector<bool> visited(10, false);
            solve(letters, vector<int>(), visited, {word1, word2, result});
            if (!solved)
            {
                cout << "No solution found." << endl;
            }
        }
    }
    
    return 0;
}
