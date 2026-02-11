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
vector <int> g[mx];
bool vis[mx];
bool isCycle;
int cnt;

void dfs(int u, int par)
{
    vis[u] = true;
    cnt++;

    for(int v : g[u]) {
        if(!vis[v]) {
            dfs(v, u);
        } else if(v != par) {
            isCycle = true;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        vis[i] = false;
    }

    bool chk = true;

    for(int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);

        if(u == v || g[u].size() > 2 || g[v].size() > 2) {
            chk = false;
        }
    }

    if(!chk) {
        cout << "NO" << endl;
        return;
    }

    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            isCycle = false;
            cnt = 0;

            dfs(i, -1);

            if(isCycle && (cnt & 1)) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int32_t main()
{
    Start

    int t = 0;
    cin >> t;

    // solve();

    while (t--)
    {
        solve();
    }

    return 0;
}