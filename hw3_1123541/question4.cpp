#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the Minimum Spanning Tree (MST) weight
int findMSTWeight(int V, vector<pair<int, int>> adj[])
{
    // Min-heap to store {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Visited array to keep track of nodes included in the MST
    vector<bool> visited(V, false);

    int mstWeight = 0; // Sum of weights of edges in the MST

    // Start with node 0 and push it to the priority queue with weight 0
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty())
    {
        // Extract the node with the smallest edge weight
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // If the node is already visited, skip it
        if (visited[node])
            continue;

        // Mark the node as visited and add its weight to the MST
        visited[node] = true;
        mstWeight += weight;

        // Add all adjacent nodes of the current node to the priority queue
        for (auto &edge : adj[node])
        {
            int adjNode = edge.first;
            int edgeWeight = edge.second;

            if (!visited[adjNode])
                pq.push({edgeWeight, adjNode});
        }
    }

    return mstWeight;
}

int main()
{
    int V, E;
    cin >> V >> E;

    // Create an adjacency list to store the graph
    vector<pair<int, int>> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // Since the graph is undirected, add edges in both directions
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Calculate the weight of the MST
    int result = findMSTWeight(V, adj);

    // Output the result
    cout << result << endl;

    return 0;
}
