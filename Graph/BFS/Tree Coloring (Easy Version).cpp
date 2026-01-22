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

const int mx = 5e5 + 123;
vector <int> g[mx];
int lev[mx];
map <int, int> mp;

void bfs(int s)
{
    memset(lev, -1, sizeof(lev));
    mp.clear();

    lev[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : g[u]) {
            if (lev[v] == -1) {
                lev[v] = lev[u] + 1;
                q.push(v);

                mp[lev[v]]++;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        g[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans = max(ans, (int)g[i].size());
    }

    ans = max(ans , ((int)g[1].size() + 1));

    // cout << ans << endl;
    bfs(1);

    int ans2 = 0;
    for(auto &u : mp) {
        ans2 = max(ans2 , u.second);
    }

    cout << max(ans , ans2) << endl;
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

