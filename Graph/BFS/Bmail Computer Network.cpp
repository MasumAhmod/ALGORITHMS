/// BFS
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int mx = 200005;
vector <int> adj[mx];
int lev[mx];
int parent[mx];

void bfs(int s)
{
    memset(lev, -1, sizeof(lev));
    memset(parent, -1, sizeof(parent));

    lev[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (lev[v] == -1) {
                lev[v] = lev[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int32_t main()
{
    int n;
    cin >> n;

    for(int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }

    bfs(1);

    vector <int> path;
    for (int i = n; i != -1; i = parent[i]) {
        path.push_back(i);
    }

    reverse(path.begin(), path.end());

    for(auto &u : path) {
        cout << u << " ";
    } cout << endl;
}


