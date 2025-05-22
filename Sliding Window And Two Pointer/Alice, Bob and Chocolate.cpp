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

    long long sum = v[0], mx = v[0];
    for (int i = 1; i < n; ++i)
    {
        if (abs(v[i] % 2) != abs(v[i - 1] % 2))
        {
            sum += v[i];
        }
        else
        {
            sum = v[i];
        }
        mx = max(mx, sum);
    }

    cout << mx << endl;
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

 
