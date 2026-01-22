///MAsum
#include <bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vii vector<long long>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define gcd __gcd
#define vall v.begin(),v.end()
#define MOD 1000000007

void solve()
{
    int n , l , r;
    cin >> n >> l >> r;

    vector <int> pre(n + 1);
    pre[0] = 0;

    for(int i = 1; i <= n; ++i) {
        if(i == r) {
            pre[i] = pre[l - 1];
        } else {
            pre[i] = i;
        }
    }

    for(int i = 1; i <= n; ++i) {
        int tmp = pre[i] ^  pre[i  - 1];
        cout << tmp << " ";
    } cout << endl;
}

int32_t main()
{
    Start

    int t = 0;
    cin >> t;

    // solve();

    while (t--)
    {
        solve();
    }

    return 0;
}

