///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vii vector<long long>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define gcd __gcd
#define MOD 1000000007

ll isOk(ll mid, ll x , const vector<ll> &v)
{
    if (v[mid] <= x) return 0;
    else return 1;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    while(m--){
        ll x;
        cin >> x;

        ll l = 0, r = n;
        while(l < r){
            ll mid = (l + r) / 2;

            if(isOk(mid, x, v) == 0)
                l = mid + 1;
            else
                r = mid;
        }

        cout << l << " ";
    }
    cout << endl;
}

int32_t main()
{
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
