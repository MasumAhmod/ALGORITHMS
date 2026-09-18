///MAsum
#include <bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vii vector<long long>
#define yes cout << Yes << endl
#define no cout << No << endl
#define gcd __gcd
#define vall v.begin(),v.end()
#define MOD 1000000007

const int mx = 3e5 + 123;
vector <int> g[mx];
bool vis[mx];
bool chk = true;
int cnt[2];
int color[mx];

void dfs(int src , int col) {
    vis[src] = true;
    color[src] = col;
    cnt[col]++;

    for(auto child : g[src]) {
        if(vis[child]) {
            int childCol = col ^ 1;

            if(childCol != color[child]){
                chk = false;
            }
            continue;
        }
        dfs(child , col ^ 1);
    }
}

void solve() {
    int n , m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        color[i] = -1;
        g[i].clear();
        vis[i] = false;
    }

    for(int i = 1; i <= m; ++i) {
        int u , v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
            dfs(i , 0);
        }

        if(chk) ans += max(cnt[0] , cnt[1]);
        cnt[0] = cnt[1] = 0;
        chk = true;
    }
    cout << ans << endl;
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
