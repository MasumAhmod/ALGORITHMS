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

const int mx = 5e5 + 123;
int sz[mx] , par[mx];

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
        sz[a] += sz[b];
        par[b] = a;
    }
}

void solve()
{
    int n , m;
    cin >> n >> m;

    init(n);
    while(m--) {
        int k;
        cin >> k;

        if(k == 0) continue;
        if(k == 1) {
            int a;
            cin >> a;

            int b = a;
            union_set(a , b);
        } else {
            int a;
            cin >> a;

            for(int i = 1; i < k; ++i) {
                int x;
                cin >> x;

                union_set(a , x);
                a = x;
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        cout << sz[find(i)] <<  ;
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
