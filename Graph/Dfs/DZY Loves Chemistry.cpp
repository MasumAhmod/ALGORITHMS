///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vii vector<long long>

const int mx = 1e5 + 123;
int vis[mx];
vi adj[mx];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : adj[u])
    {
        if(vis[v] == 0)
        {
            dfs(v);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            cnt++;
            dfs(i);
        }
    }
    cout << (1LL << (n - cnt)) << endl;
}

int32_t main()
{
    ///cODE BY Masum
    optimize();

    solve();

    /* int t;
     cin >> t;

     while (t--)
     {
         solve();
     }*/

    return 0;
}
