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

#define N 500005

int n;
vector <int> g[N];
int inDegree[N];

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        inDegree[i] = 0;
    }

    for(int i = 1; i < n; ++i) {
        int u , v , x , y;
        cin >> u >> v >> x >> y;

        if(x >= y) {
            g[v].push_back(u);
            inDegree[u]++;
        } else {
            g[u].push_back(v);
            inDegree[v]++;
        }
    }

    queue <int> q;
    for(int i = 1; i <= n; ++i) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector <int> topological_order;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        topological_order.push_back(u);

        for(auto v : g[u]) {
            inDegree[v]--;

            if(inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    vector <int> ans(n + 1 , 0);
    for(int i = 1; i <= n; ++i) {
        ans[topological_order[i - 1]] = i;
    }

    for(int i = 1; i <= n; ++i) {
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
