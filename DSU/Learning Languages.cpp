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

const int mx = 2e5 + 123;
int sz[mx];
vector <int> par(mx , 0);
set <int> st;

void init(int x) {
    if(par[x] == 0) {   
        par[x] = x;
        sz[x] = 1;

        st.insert(x);
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
    int n , m;
    cin >> n >> m;

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        if(k == 0) {
            ans++;
            continue;
        }

        vector <int> a(k);
        for(int j = 0; j < k; ++j) {
            cin >> a[j];

            init(a[j]);
        }

        for(int j = 1; j < k; ++j) {
            union_set(a[j - 1] , a[j]);
        }
    }

    map <int , int> mp;
    for(auto &u :st) {
        int root = find(u);
        mp[root]++;
    }

    int mp_sz = mp.size();

    if(mp_sz > 0) {
        mp_sz--;
    }

    ans += mp_sz;
    cout << ans << endl;
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
