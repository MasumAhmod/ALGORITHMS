#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define vi vector<int>

const int mx = 1e5 + 123;
vi adj[mx];
bool vis[mx];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : adj[u]){
        if(vis[v] == 0){
            dfs(v);
        }
    }
}

int main()
{
    int n , m;
    cin >> n >> m;

    while(m--){
        int u , v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
}
