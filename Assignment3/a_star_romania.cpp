// #include <bits/stdc++.h>
// using namespace std;

// class Edge
// {
// public:
//     string source, dest;
//     int weight;

//     Edge(string source, string dest, int weight) : source(source), dest(dest), weight(weight) {}
// };

// class PQNode
// {
// public:
//     string node;
//     int priority;
//     int distance;  

//     PQNode(string node, int priority, int distance) : node(node), priority(priority), distance(distance) {}

//     bool operator<(const PQNode &other) const
//     {
//         return priority > other.priority;
//     }
// };

// class Graph
// {
// public:
//     unordered_map<string, vector<Edge>> adjList;

//     Graph(vector<Edge> const &edges)
//     {
//         for (auto &edge : edges)
//         {
//             adjList[edge.source].push_back(edge);
//         }
//     }
// };

// unordered_map<string, int> heuristic = {
//     {"Arad", 366}, {"Bucharest", 0}, {"Craiova", 160}, {"Dobreta", 242}, {"Eforie", 161}, {"Fagaras", 176}, {"Giurgiu", 77}, {"Hirsova", 151}, {"Iasi", 226}, {"Lugoj", 244}, {"Mehadia", 241}, {"Neamt", 234}, {"Oradea", 380}, {"Pitesti", 100}, {"Rimnicu Vilcea", 193}, {"Sibiu", 253}, {"Timisoara", 329}, {"Urziceni", 80}, {"Vaslui", 199}, {"Zerind", 374}};

// void astar(const Graph &graph, string src, string dest)
// {
//     priority_queue<PQNode> pq;
//     unordered_set<string> visited;
//     unordered_map<string, string> path;

//     pq.push(PQNode(src, 0, 0));

//     while (!pq.empty())
//     {
//         string currentNode = pq.top().node;
//         int currentPriority = pq.top().priority;
//         int currentDistance = pq.top().distance;
//         pq.pop();                

//         visited.insert(currentNode);

//         if (currentNode == dest)
//         {
//             cout << "Path: ";
//             string node = dest;
//             vector<string> reversePath;
//             while (node != src)
//             {
//                 reversePath.push_back(node);
//                 node = path[node];
//             }
//             reversePath.push_back(src);
//             for (int i = reversePath.size() - 1; i > 0; i--)
//             {
//                 cout << reversePath[i] << " -> ";
//             }
//             cout << reversePath[0] << endl;
//             cout << "Total Distance: " << currentDistance;
//             break;
//         }

//         for (const Edge &edge : graph.adjList.at(currentNode))
//         {
//             if (visited.find(edge.dest) == visited.end())
//             {
//                 int priority = heuristic.at(edge.dest);
//                 int newDistance = currentDistance + edge.weight;
//                 pq.push(PQNode(edge.dest, priority + newDistance, newDistance));
//                 path[edge.dest] = currentNode;
//             }
//         }
//     }
// }

// int main()
// {

//     vector<Edge> edges = {
//         Edge("Arad", "Zerind", 75), Edge("Arad", "Sibiu", 140), Edge("Arad", "Timisoara", 118),
//         Edge("Zerind", "Oradea", 71), Edge("Oradea", "Sibiu", 151), Edge("Sibiu", "Fagaras", 99),
//         Edge("Sibiu", "Rimnicu Vilcea", 80), Edge("Timisoara", "Lugoj", 111), Edge("Lugoj", "Mehadia", 70),
//         Edge("Mehadia", "Drobeta", 75), Edge("Drobeta", "Craiova", 120), Edge("Craiova", "Rimnicu Vilcea", 146),
//         Edge("Craiova", "Pitesti", 138), Edge("Rimnicu Vilcea", "Pitesti", 97), Edge("Fagaras", "Bucharest", 211),
//         Edge("Pitesti", "Bucharest", 101), Edge("Bucharest", "Giurgiu", 90), Edge("Bucharest", "Urziceni", 85),
//         Edge("Urziceni", "Vaslui", 142), Edge("Urziceni", "Hirsova", 98), Edge("Vaslui", "Iasi", 92),
//         Edge("Iasi", "Neamt", 87), Edge("Hirsova", "Eforie", 86)};

//     Graph graph(edges);

//     string src = "Arad";
//     string dest = "Bucharest";

//     astar(graph, src, dest);

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    string source, dest;
    int weight;

    Edge(string source, string dest, int weight) : source(source), dest(dest), weight(weight) {}
};

class Graph
{
public:
    unordered_map<string, vector<Edge>> adjList;

    Graph(vector<Edge> const &edges)
    {
        for (auto &edge : edges)
        {
            adjList[edge.source].push_back(edge);
        }
    }
};

unordered_map<string, int> heuristic = {
    {"Arad", 366}, {"Bucharest", 0}, {"Craiova", 160}, {"Dobreta", 242}, {"Eforie", 161}, {"Fagaras", 176}, {"Giurgiu", 77},
    {"Hirsova", 151}, {"Iasi", 226}, {"Lugoj", 244}, {"Mehadia", 241}, {"Neamt", 234}, {"Oradea", 380}, {"Pitesti", 100},
    {"Rimnicu Vilcea", 193}, {"Sibiu", 253}, {"Timisoara", 329}, {"Urziceni", 80}, {"Vaslui", 199}, {"Zerind", 374}};

void astar(const Graph &graph, string src, string dest)
{
    // Priority queue with pair<int, pair<string, int>>
    priority_queue<pair<int, pair<string, int>>, vector<pair<int, pair<string, int>>>, greater<pair<int, pair<string, int>>>> pq;
    unordered_set<string> visited;
    unordered_map<string, string> path;

    pq.push({heuristic[src], {src, 0}}); // {priority, {node, distance}}

    while (!pq.empty())
    {
        string currentNode = pq.top().second.first;
        int currentPriority = pq.top().first;
        int currentDistance = pq.top().second.second;
        pq.pop();

        if (visited.find(currentNode) != visited.end())
        {
            continue;
        }

        visited.insert(currentNode);

        if (currentNode == dest)
        {
            cout << "Path: ";
            string node = dest;
            vector<string> reversePath;
            while (node != src)
            {
                reversePath.push_back(node);
                node = path[node];
            }
            reversePath.push_back(src);
            for (int i = reversePath.size() - 1; i > 0; i--)
            {
                cout << reversePath[i] << " -> ";
            }
            cout << reversePath[0] << endl;
            cout << "Total Distance: " << currentDistance << endl;
            return;
        }

        for (const Edge &edge : graph.adjList.at(currentNode))
        {
            if (visited.find(edge.dest) == visited.end())
            {
                int newDistance = currentDistance + edge.weight;
                int priority = newDistance + heuristic.at(edge.dest);
                pq.push({priority, {edge.dest, newDistance}});
                path[edge.dest] = currentNode;
            }
        }
    }
}

int main()
{
    vector<Edge> edges = {
        Edge("Arad", "Zerind", 75), Edge("Arad", "Sibiu", 140), Edge("Arad", "Timisoara", 118),
        Edge("Zerind", "Oradea", 71), Edge("Oradea", "Sibiu", 151), Edge("Sibiu", "Fagaras", 99),
        Edge("Sibiu", "Rimnicu Vilcea", 80), Edge("Timisoara", "Lugoj", 111), Edge("Lugoj", "Mehadia", 70),
        Edge("Mehadia", "Drobeta", 75), Edge("Drobeta", "Craiova", 120), Edge("Craiova", "Rimnicu Vilcea", 146),
        Edge("Craiova", "Pitesti", 138), Edge("Rimnicu Vilcea", "Pitesti", 97), Edge("Fagaras", "Bucharest", 211),
        Edge("Pitesti", "Bucharest", 101), Edge("Bucharest", "Giurgiu", 90), Edge("Bucharest", "Urziceni", 85),
        Edge("Urziceni", "Vaslui", 142), Edge("Urziceni", "Hirsova", 98), Edge("Vaslui", "Iasi", 92),
        Edge("Iasi", "Neamt", 87), Edge("Hirsova", "Eforie", 86)};

    Graph graph(edges);

    string src = "Arad";
    string dest = "Bucharest";

    astar(graph, src, dest);

    return 0;
}
