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

const int mx = 5e5 + 123;
vector <int> g[mx];
int lev[mx];

void bfs(int s)
{
    memset(lev, -1, sizeof(lev));

    lev[s] = 0;
    queue<int> q;
    q.push(s);

        int u = q.front();
        q.pop();

        for (auto v : g[u]) {
            if (lev[v] == -1) {
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int n , a , b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; ++i) {
        g[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(a);
    cout << lev[b];
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
