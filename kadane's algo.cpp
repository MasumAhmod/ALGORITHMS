///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &u : v) cin >> u;

    int sum = 0, mx = v[0] , ans = v[0];
    for (int i = 0; i < n; ++i) {
        sum += v[i];

        ans = max(ans , sum);

        if(sum <= 0){
            sum = 0;
        }
    }

    cout << ans << endl;
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
