#include <iostream>
#include <vector>
using namespace std;

// Helper function to perform DFS traversal recursively
void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfsResult) {
    visited[node] = true;           // Mark the current node as visited
    dfsResult.push_back(node);      // Add the current node to the result

    // Visit all unvisited neighbors
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, dfsResult);
        }
    }
}

// Function to perform DFS traversal
vector<int> dfsTraversal(int V, vector<vector<int>>& adj) {
    vector<int> dfsResult;         // To store the DFS traversal order
    vector<bool> visited(V, false); // To keep track of visited nodes

    // Start DFS from vertex 0
    dfsHelper(0, adj, visited, dfsResult);

    return dfsResult;
}

int main() {
    // Different input adjacency list
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 4}, {0, 4}, {2, 3}};
    int V = adj.size(); // Number of vertices

    // Perform DFS traversal
    vector<int> dfsResult = dfsTraversal(V, adj);

    // Print the DFS traversal
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
