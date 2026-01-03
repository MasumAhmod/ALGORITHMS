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
int col[mx] , ans;

void dfs(int root , int par)
{
    for(auto &u : g[root]) {
        if(u != par) {
            if(col[u] != col[root]) {
                ans++;
            }

            dfs(u , root);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for(int i = 2; i <= n; ++i){
        int u;
        cin >> u;

        g[u].push_back(i);
        g[i].push_back(u);
    }

    for(int i = 1;  i <= n; ++i) {
        cin >> col[i];
    }

    ans = 1;
    dfs(1 ,  -1);
    cout << ans << endl;
}

int32_t main()
{
    Start

    int t = 0;
    //cin >> t;

    solve();

    while (t--)
    {
        solve();
    }

    return 0;
}
