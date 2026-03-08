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

const int mx = 1e3 + 123;
int par[mx], sz[mx];
int n , m;

void init() {
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

void dsu_join(int a, int b) {
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
    cin >> n >> m;

    init();

    for(int i = 1; i <= m; ++i) {
        int u , v;
        cin >> u >> v;

        dsu_join(u , v);
    }

    //code for chk connected component
    set <int> st;
    for(int i = 1; i <= n; ++i) {
        st.insert(find(i));
    }

    if((st.size() == 1) && (m == n)) {
        cout << FHTAGN! << endl;
    } else {
        cout << NO << endl;
    } 
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
