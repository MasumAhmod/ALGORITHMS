///MAsum
#include <bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vii vector<long long>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define gcd __gcd
#define vall v.begin(),v.end()
#define MOD 1000000007

const int mx = 2e5 + 123;
vector <int> g[mx] , v;
bool vis[mx];
int deg[mx];
// int n , m;

void dfs(int node)
{
    vis[node] = 1;
    v.push_back(node);

    for(auto child : g[node]){
        if(vis[child] == 0){
            dfs(child);
        }
    }
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for(int i = 1; i <= m; ++i){
        int u , v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            v.clear();
            dfs(i);
            bool chk = true;

            for(auto &u : v) {
                if(deg[u] != 2) {
                    chk = false;
                    break;
                }
            }

            if(chk) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    Start

    int t = 0;
    //cin >> t;

    solve();

    while (t--)
    {
        solve();
    }

    return 0;
}
