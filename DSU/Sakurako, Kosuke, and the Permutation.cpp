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
int par[mx] , sz[mx];

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int i) {
    if(par[i] == i) {
        return i;
    }

    return par[i] = find(par[i]);
}

void union_set(int a , int b) {
    a = find(a);
    b = find(b);

    if(a != b) {
        if(sz[a] < sz[b]) swap(a , b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

void solve()
{
    int n;
    cin >> n;

    init(n);

    vector <int> v(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
        union_set(i , v[i]);
    }

    map <int , int> mp;
    for(int i = 1; i <= n; ++i) {
        int root = find(i);
        mp[root]++;
    }

    int ans = 0;
    for(auto &u : mp) {
        if(u.second > 2) {
            ans += ((u.second - 1) / 2);
        }
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
