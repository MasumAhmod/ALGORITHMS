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
int dis[mx], subSz[mx];

void dfs_iterative(int root) {
    stack < pair <int , int>> st; // {node, parent}
    st.push({root, -1});

    while (!st.empty()) {
        auto [u, p] = st.top();
        st.pop();

        if(u > 0) {
            st.push({-u, p}); 
            subSz[u] = 1;

            for (int v : g[u]) {
                if (v != p) {
                    dis[v] = dis[u] + 1;
                    st.push({v, u});
                }
            }
        } else {
            u = -u;
            for(int v : g[u]) {
                if(v != p) {
                    subSz[u] += subSz[v];
                }
            }
        }
    }
}

void solve()
{
    int n , k;
    cin >> n >> k;

    for(int i = 1; i < n; ++i) {
        int u , v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dis[1] = 1;
    dfs_iterative(1);

    vector <int> cur;
    for(int i = 1; i <= n; ++i) {
        cur.push_back({subSz[i] - dis[i]});
    }

    sort(cur.rbegin() , cur.rend());
    
    while(k--) {
        cur.pop_back();
    }

    int ans = 0;
    for (auto &u : cur) {
        ans += u;
    }

    cout << ans << endl;
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