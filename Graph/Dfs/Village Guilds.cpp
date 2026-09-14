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

const int mx = 3e5 + 123;
vector <int> graph[mx];
int dep[mx];

void dfs1(int u , int p = 0) {
    dep[u] = 1;

    for(auto &v : graph[u]) {
        if(v == p) continue;
        dfs1(v , u);
        dep[u] = max(dep[u] , (1 + dep[v]));
    }
}

void dfs(int u , int p , int &ans) {
    for(auto &v : graph[u]) {
        if(v == p) continue;
        dfs(v , u , ans);
    }

    vector <int> d;
    for(auto v : graph[u]) {
        if(v == p) continue;
        d.push_back(dep[v]);
    }

    sort(d.begin() , d.end());
    ans++;

    if(d.size() > 1) {
        d.pop_back();
        ans += d.back();
    }
}

void solve() {
    int n;
    cin >> n;

    for(int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        graph[u].push_back(i);
        graph[i].push_back(u);
    }

    dfs1(1);
    int ans = 0;
    dfs(1 , 0 , ans);
    cout << ans << endl;

    for(int i = 1; i <= n; ++i) {
        graph[i].clear();
        dep[i] = 0;
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
