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

vector <int> g[mx];
bool vis[mx];

void dfs(int src) {
	priority_queue <int , vector <int> , greater <int>> q;

	q.push(src);
	vis[src] = 1;

	while(!q.empty()) {
		int u = q.top();
		
		cout << u << " ";

		q.pop();

		for(auto &v : g[u]) {
			if(!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

void solve()
{
	int n , m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        vis[i] = 0;
    }

    for(int i = 1; i <= m; ++i) {
        int u , v;
        cin >> u >> v;

        if(u != v) {
        	g[u].push_back(v);
        	g[v].push_back(u);
        }
    }
    dfs(1);
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