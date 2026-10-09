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

const int mx = 1e6 + 123;

vector <pair <int , int>> g[mx];
int dist[mx];
int par[mx];

void dijkstra(int src , int n) {
    for(int i = 1; i <= n; ++i) {
        dist[i] = LLONG_MAX;
    }

    priority_queue <pair <int , int> , vector <pair <int , int>> , greater <pair <int , int>>> pq;
    pq.push({0 , src});
    dist[src] = 0;

        int u = pq.top().first;
        int v = pq.top().second;

        pq.pop();
        if(dist[v] < u) continue;

        for(auto &child : g[v]) {
            if(u + child.second < dist[child.first]) {
                dist[child.first] = u + child.second;
                pq.push({dist[child.first] , child.first});
                par[child.first] = v;
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
    }

    for(int i = 1; i <= m; ++i) {
        int u , v , wt;
        cin >> u >> v >> wt;

        g[u].push_back({v , wt});
        g[v].push_back({u , wt});
    }

    dijkstra(1 , n);
    if(par[n] == 0) {
        cout << -1 << endl;
        return;
    }

    vector <int> v = {n};
    int x = n;
    while(par[x] != 0) {
        v.push_back(par[x]);
        x = par[x];
    }

    reverse(v.begin() , v.end());
    for(auto &u : v) {
        cout << u <<  ;
    } cout << endl;
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
