#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal
vector<int> bfsTraversal(int V, vector<vector<int>>& adj) {
    vector<int> bfsResult;         // To store the BFS traversal order
    vector<bool> visited(V, false); // To keep track of visited nodes
    queue<int> q;                  // Queue to implement BFS

    // Start BFS from vertex 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        bfsResult.push_back(current);

        // Visit all neighbors of the current node
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return bfsResult;
}

int main() {
    // New input adjacency list
    vector<vector<int>> adj = {{1, 3}, {0, 2, 3}, {1, 4}, {0, 1, 4}, {2, 3}};
    int V = adj.size(); // Number of vertices

    // Perform BFS traversal
    vector<int> bfsResult = bfsTraversal(V, adj);

    // Print the BFS traversal
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
