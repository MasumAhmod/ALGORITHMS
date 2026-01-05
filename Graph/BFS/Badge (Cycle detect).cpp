/// BFS
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int mx = 200005;
vector <int> adj[mx];
bool vis[mx];
int ans = -1;

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : adj[u]){
        if(vis[v] == 0){
            dfs(v);
        } else if(ans == -1) {
            ans = v;
        }
    }
}

int32_t main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        int u;
        cin >> u;
        adj[i].push_back(u);
    }

    for(int i = 1; i <= n; ++i) {
        dfs(i);
        cout << ans << ' ';
        ans = -1;
        memset(vis, 0, sizeof(vis));
    }
}


