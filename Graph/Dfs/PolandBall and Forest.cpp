///MAsum
#include <bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vii vector<long long>
#define yes cout << YES << endl
#define no cout << NO << endl
#define gcd __gcd
#define vall v.begin(),v.end()
#define MOD 1000000007

const int mx = 1e4 + 123;
vector <int> g[mx];
bool vis[mx];

void dfs(int u) {
    vis[u] = true;

    for(auto &v : g[u]) {
            dfs(v);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        int u;
        cin >> u;

        g[u].push_back(i);
        g[i].push_back(u);
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt << endl;
}

int32_t main()
{
    Start

    int t = 0;
    // cin >> t;

    solve();

    while (t--)
    {
        solve();
    }

    return 0;
}
