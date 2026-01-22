///Masum
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
    long long n , l , r , k;
    cin >> n >> l >> r >> k;

    if(n & 1) {
        cout << l << endl;
        return;
    }

    if(n == 2) {
        cout << -1 << endl;
        return;
    }

    long long bitt = __lg(l); /// last index where l has a set bit
    bitt++;

    long long val = (1LL << bitt);
    if(val > r) {
        cout << -1 << endl;
        return;
    }

    if(k <= n - 2) {
        cout << l << endl;
    } else {
        cout << val << endl;
    }
}

int32_t main()
{
    /// CODE BY Masum
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // solve();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

