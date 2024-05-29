#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Node {
public:
    int value;
    bool isGoal;
    bool isAndNode;
    bool isOrNode;
    unordered_map<int, int> children; // Map of child node value to cost

    Node(int value, bool isGoal = false, bool isAndNode = false, bool isOrNode = false)
        : value(value), isGoal(isGoal), isAndNode(isAndNode), isOrNode(isOrNode) {}

    void addChild(int childValue, int cost) {
        children[childValue] = cost;
    }

    int calculateCost(vector<Node*>& nodes, unordered_map<int, int>& costs, unordered_map<int, bool>& visited) {
        if (isGoal) {
            costs[value] = 0; // Cost to reach a goal node is 0
            return 0;
        }

        if (visited[value]) {
            return costs[value]; // Return cost if already visited
        }

        visited[value] = true;

        if (isAndNode) {
            // For AND nodes, calculate the cost as the sum of costs of all children nodes
            int totalCost = 0;
            for (auto& [childValue, edgeCost] : children) {
                totalCost += edgeCost + nodes[childValue]->calculateCost(nodes, costs, visited);
            }
            costs[value] = totalCost;
        } else if (isOrNode) {
            // For OR nodes, calculate the cost as the minimum of costs of all children nodes
            int minCost = INT_MAX;
            for (auto& [childValue, edgeCost] : children) {
                minCost = min(minCost, edgeCost + nodes[childValue]->calculateCost(nodes, costs, visited));
            }
            costs[value] = minCost;
        }

        return costs[value];
    }
};

void solveAOStar(Node* startNode, vector<Node*>& nodes) {
    unordered_map<int, int> costs;
    unordered_map<int, bool> visited;
    int cost = startNode->calculateCost(nodes, costs, visited);

    cout << "Minimum cost to reach a goal from node " << startNode->value << " is: " << cost << endl;
}

int main() {
    vector<Node*> nodes;
    nodes.push_back(new Node(0, false, true));
    nodes.push_back(new Node(1, false, false, true));
    nodes.push_back(new Node(2, false, false, true));
    nodes.push_back(new Node(3, false, false, false));
    nodes.push_back(new Node(4, false, false, false));
    nodes.push_back(new Node(5, true));

    // Define node relationships
    nodes[0]->addChild(1, 1);
    nodes[0]->addChild(2, 2);
    nodes[1]->addChild(3, 3);
    nodes[1]->addChild(4, 4);
    nodes[2]->addChild(5, 5); 

    solveAOStar(nodes[0], nodes);

    // Clean up allocated nodes
    for (auto& node : nodes) {
        delete node;
    }

    return 0;
}
