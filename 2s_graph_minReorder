#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int minReorder(int n, vector<vector<int>>& connections) {
    // Create an adjacency list for the graph
    unordered_map<int, vector<pair<int, bool>>> graph;
    for (const auto& conn : connections) {
        graph[conn[0]].emplace_back(conn[1], true);  // true indicates original direction
        graph[conn[1]].emplace_back(conn[0], false); // false indicates reverse direction
    }
    
    int changes = 0;
    queue<int> q;
    unordered_set<int> visited;
    q.push(0); // Start from the capital city
    visited.insert(0);

    // BFS traversal
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (const auto& [neighbor, isOriginal] : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                // If the edge is in the original direction, we need to reverse it
                if (isOriginal) {
                    ++changes;
                }
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    
    return changes;
}

int main() {
    vector<vector<int>> connections1 = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << "Example 1 Output: " << minReorder(6, connections1) << endl;

    vector<vector<int>> connections2 = {{1,0},{1,2},{3,2},{3,4}};
    cout << "Example 2 Output: " << minReorder(5, connections2) << endl;

    vector<vector<int>> connections3 = {{1,0},{2,0}};
    cout << "Example 3 Output: " << minReorder(3, connections3) << endl;

    return 0;
}
