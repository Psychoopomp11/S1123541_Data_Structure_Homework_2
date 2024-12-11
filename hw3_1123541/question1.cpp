#include <iostream>
#include <vector>
using namespace std;

// Function to create and return an adjacency list
vector<vector<int>> createAdjacencyList(int V, vector<vector<int>>& edges) {
    // Initialize an adjacency list
    vector<vector<int>> adjList(V);

    // Iterate through all edges and populate the adjacency list
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since the graph is undirected
    }

    return adjList;
}

// Function to print the adjacency list (for verification)
void printAdjacencyList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    // New input with 4 vertices and 5 edges
    int V = 4, E = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}};
    
    // Create the adjacency list
    vector<vector<int>> adjList = createAdjacencyList(V, edges);

    // Print the adjacency list
    printAdjacencyList(adjList);

    return 0;
}
