///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'

ll isOk(ll b, ll y)
{
    if (b * b * b < y) return 0;
    else return 1;
}

void solve()
{
    ll n;
    cin >> n;

    int chk = 0;

    for (ll i = 1; i * i * i <= n; ++i)
    {
        ll l = 1, r = 1e4;

        ll y = n - (i * i * i);
        while (l < r)
        {
            ll mid = (l + r) / 2;

            if (isOk(mid, y) == 0)
                l = mid + 1;
            else
                r = mid;
        }

        if(l * l * l == y){
            chk = 1;
            break;
        }
    }
    if(chk == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main()
{
    optimize();

    //solve();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
