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
pair <int , int> tree[4 * mx];
 
///Mergee Function
pair <int , int> combine(pair <int , int> a , pair <int , int> b) {
    if(a.first == b.first) {
        return {a.first , (a.second + b.second)};
    }
 
    return min(a , b);
}
 
void build(int n, int l, int r) {
    if(l == r) {
        tree[n] = {inf , 0};
        return;
    }
 
    int mid = (l + r) / 2;
    build(2 * n, l, mid);
    build(2 * n + 1, mid + 1, r);
 
    // pull
    tree[n] = combine(tree[2 * n] , tree[2 * n + 1]);
}
 
void update(int n, int l, int r, int i, int v) {
    // baire kina
    if(i < l ||  i > r) {
        return;
    }
 
    if(l == r) {
        tree[n] = {v , 1};
        return;
    }
 
    int mid = (l + r) / 2;
    update(2 * n, l, mid, i, v);
    update(2 * n + 1, mid + 1, r, i, v);
 
    // pull
    tree[n] = combine(tree[2 * n] , tree[2 * n + 1]);
}
 
pair <int ,int> query(int n, int l, int r, int i, int j) {
 
    // // valid range check if needed
    // if(j < i) {
    //     return 0;
    // }
 
    if(i > r || j < l) {
        return {inf , 0};
    }
 
    if(l >= i && r <= j) {
        return tree[n];
    }
 
    int mid = (l + r) / 2;
 
    return combine(query(2 * n, l, mid, i, j) , query(2 * n + 1, mid + 1, r, i, j));
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
 
            pair <int ,int> ans = query(1 , 1 , n , i + 1 , j);
 
            cout << ans.first <<   << ans.second << endl;
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
