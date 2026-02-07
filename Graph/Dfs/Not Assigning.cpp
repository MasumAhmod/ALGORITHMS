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

const int mx = 1e5 + 123;

vector <pair <int , int>> g[mx];
int ans[mx];
int deg[mx];

void dfs(int src , int par , int f) {
	for(auto u : g[src]) {
		if(u.first == par) continue;

		if(f) {
			ans[u.second] = 2;
		} else {
			ans[u.second] = 5;
		}

		dfs(u.first , src , f^1);
	}
}

void solve()
{
	int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        deg[i] = 0;
        ans[i] = 0;
    }

    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        deg[u]++;
        deg[v]++;
    }

    int chk = -1;

    for(int i = 1; i <= n; ++i) {
    	if(deg[i] > 2) {
    		cout << -1 << endl;
    		return;
    	}

    	if(deg[i] == 1) {
    		chk = i;
    	}
    }

    dfs(chk , 0 , 0);

    for(int i = 1; i < n; ++i) {
    	cout << ans[i] << " ";
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