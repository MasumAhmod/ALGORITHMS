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
int d[mx] , th[mx];
int pr[mx] , gp[mx];

void dfs1(int u , int p , int gpp) {
    pr[u] = p;
    gp[u] = gpp;

    for(auto &child : g[u]) {
        if(child == p) continue;
        dfs1(child , u , p);
    }
}

void dfs(int u , int p) {
    if(u == 1) {
        th[u] = d[u];
    } else {
        th[u] = d[u];
        int sum = d[u] - d[p];
        int gpp = gp[u];

        if(gp[u] != 0) {
            sum += max(0LL , th[gpp]);
        }

        th[u] = max(th[u] , sum);
    }

    for(auto &child : g[u]) {
        if(child == p) continue;
        dfs(child , u);
    }
}

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        g[i].clear();
        cin >> d[i];
    }

    for(int i = 1; i <= n - 1; ++i) {
        int u , v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1 , 0 , 0);
    dfs(1 , 0);
    for(int i = 1; i <= n; ++i) {
        cout << th[i] <<  ;
    } cout << endl;
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
