/// BFS
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define vi vector<int>

const int mx = 1e5 + 123; // Maximum number of nodes
vi adj[mx]; // Adjacency list to store the graph
int lev[mx]; // Level array to store distance from source

// Breadth-First Search function
void bfs(int s)
{
    memset(lev, -1, sizeof(lev)); // Initialize all levels to -1 (unvisited)

    lev[s] = 0; // Level of source node is 0
    queue<int> q; // Queue for BFS
    q.push(s); // Start BFS from node s

    while (!q.empty()) {
        int u = q.front(); // Get current node from queue
        q.pop();

        for (auto v : adj[u]) { // Traverse all adjacent nodes
            if (lev[v] == -1) { // If not visited
                lev[v] = lev[u] + 1; // Set level of neighbor
                q.push(v); // Add neighbor to queue
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m; // Read number of nodes and edges

    while (m--) {
        int u, v;
        cin >> u >> v; // Read each edge
        adj[u].pb(v); // Add edge u -> v
        adj[v].pb(u); // Add edge v -> u (undirected)
    }

    bfs(1); // Start BFS from node 1

    cout << lev[n] << endl; // Print the level (shortest distance) of node n from node 1
}
