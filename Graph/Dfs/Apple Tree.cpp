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
vector<int> g[mx];
int cnt[mx];

void dfs(int u , int parent)
{
    ///Leaf node
    if(g[u].size() == 1 && g[u].front() == parent) {
        cnt[u] = 1;
    } else {
        for(auto v : g[u]) {
            if(v != parent) {
                dfs(v , u);
                cnt[u] += cnt[v];
            }
        }
    }
}

void solve()
{
    int node;
    cin >> node;

    for(int i = 1; i <= node; ++i) {
        g[i].clear();
        cnt[i] = 0;
    }

    for(int i = 1; i < node; ++i) {
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1 , -1);

    int q;
    cin >> q;
    while(q--) {
        int x , y;
        cin >> x >> y;
        cout << cnt[x] * cnt[y] << endl;
    }
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

