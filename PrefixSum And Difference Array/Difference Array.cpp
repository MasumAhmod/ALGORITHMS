///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

void solve()
{
    ///Difference Array
    int n , q;
    cin >> n >> q;

    vector <int> v(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }

    vector <int> pre(n + 1 , 0);

    while(q--){
        int l , r, x;
        cin >> l >> r >> x;

        pre[l] += x;
        pre[r + 1] -= x;
    }

    for(int i = 1; i <= n; ++i){
        pre[i] += pre[i - 1];
    }

    for(int i = 1; i <= n; ++i){
        v[i] += pre[i];
    }

    for(int i = 1; i <= n; ++i){
        cout << v[i] << " ";
    }

    cout << endl;
}

int32_t main()
{
    ///cODE BY Masum
    optimize();

    solve();

    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     solve();
    // }

    return 0;
}
