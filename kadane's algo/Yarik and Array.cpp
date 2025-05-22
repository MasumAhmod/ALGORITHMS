///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define gcd __gcd
#define MOD 1000000007

void solve()
{
    long long n;
    cin >> n;

    vector<long long> v(n);
    for (auto &u : v) cin >> u;

    long long sum = 0, mx = v[0];
    for (int i = 0; i < n; ++i)
    {
        if(i > 0 && (abs(v[i - 1]) % 2 == abs(v[i]) % 2))
        {
            sum = v[i];

            mx = max(mx, sum);
        }
        else
        {
            sum = max(sum + v[i] , v[i]);

            mx = max(mx , sum);
        }
    }

    cout << mx << endl;
}

int32_t main()
{
    optimize();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
