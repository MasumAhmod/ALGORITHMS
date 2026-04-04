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

const int mx = 1e5 + 123;
int tree[4 * mx] , lazy[4 * mx];

void propagate(int n , int l, int r) {
    if(lazy[n] == -1) {
        return;
    }
    
    tree[n] = (r - l + 1) * lazy[n];

    if(l < r) { //not the leaf node
        lazy[2 * n] = lazy[n];
        lazy[2 * n + 1] = lazy[n];
    }

    lazy[n] = -1; ///default
}

void update(int n, int l, int r, int i, int j, int v) {
    propagate(n , l , r);
    // baire kina
    if(j < l || i > r) {
        return;
    }

    if(l >= i && r <= j) {
        lazy[n] = v;
        propagate(n , l , r);
        return;
    }

    int mid = (l + r) / 2;
    update(2 * n, l, mid, i, j, v);
    update(2 * n + 1, mid + 1, r, i, j, v);

    // pull
    tree[n] = tree[2 * n] + tree[2 * n + 1];
}

long long query(int n, int l, int r, int i, int j) {

    propagate(n , l , r);

    if(i > r || j < l) {
        return 0LL;
    }

    if(l >= i && r <= j) {
        return tree[n];
    }

    int mid = (l + r) / 2;

    return query(2 * n, l, mid, i, j) + query(2 * n + 1, mid + 1, r, i, j);
}

void solve() {
    int n , q;
    cin >> n >> q;

    while(q--) {
        int ty;
        cin >> ty;

        if(ty == 1) {
            int l , r , v;
            cin >> l >> r >> v;

            l += 1;

            update(1 , 1 , n , l , r , v);
        } else {
            int l , r;
            cin >> l >> r;

            l += 1;

            cout << query(1 , 1 , n , l , r) << endl;
        }
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
