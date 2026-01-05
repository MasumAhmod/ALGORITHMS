#include <bits/stdc++.h>
using namespace std;

#define N 500005

int n , m;
vector <int> adj[N];
int inDegree[N];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue <int> q;
    for(int i = 1; i <= n; ++i) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector <int> topological_order;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        topological_order.push_back(u);

        for(auto v : adj[u]) {
            inDegree[v]--;

            if(inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    for(auto u : topological_order) {
        cout << u << " ";
    }
    cout << endl;

    return 0;
}


