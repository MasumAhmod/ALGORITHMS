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
#define inf 1e10
 
const int mx = 1e5 + 123;
int tree[4 * mx];
 
void build(int n, int l, int r) {
    if(l == r) {
        tree[n] = inf;
        return;
    }
 
    int mid = (l + r) / 2;
    build(2 * n, l, mid);
    build(2 * n + 1, mid + 1, r);
 
    // pull
    tree[n] = min(tree[2 * n] , tree[2 * n + 1]);
}
 
void update(int n, int l, int r, int i, int v) {
    // baire kina
    if(i < l ||  i > r) {
        return;
    }
 
    if(l == r) {
        tree[n] = v;
        return;
    }
 
    int mid = (l + r) / 2;
    update(2 * n, l, mid, i, v);
    update(2 * n + 1, mid + 1, r, i, v);
 
    // pull
    tree[n] = min(tree[2 * n] , tree[2 * n + 1]);
}
 
long long query(int n, int l, int r, int i, int j) {
 
    // // valid range check if needed
    // if(j < i) {
    //     return 0;
    // }
 
    if(i > r || j < l) {
        return inf;
    }
 
    if(l >= i && r <= j) {
        return tree[n];
    }
 
    int mid = (l + r) / 2;
 
    return min(query(2 * n, l, mid, i, j) , query(2 * n + 1, mid + 1, r, i, j));
 
 
}
 
void solve() {
    int n , q;
    cin >> n >> q;
 
    build(1 , 1 , n);
 
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
 
        update(1 , 1 , n , i , x);
    }
 
    while(q--) {
        int ty;
        cin >> ty;
 
        if(ty == 1) {
            int i , v;
            cin >> i >> v;
 
            update(1 , 1 , n , i + 1 , v);
        } else {
            int i , j;
            cin >> i >> j;
 
            cout << query(1 , 1 , n , i + 1 , j) << endl;
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
