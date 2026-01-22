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

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> pre(200002, 0);

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        pre[l] += 1;
        if (r + 1 <= 200000) {
            pre[r + 1] -= 1;
        }
    }

    for (int i = 1; i <= 200000; ++i) {
        pre[i] += pre[i - 1];
    }

    vector<int> v(200001, 0);
    for (int i = 1; i <= 200000; ++i) {
        if (pre[i] >= k) {
            v[i] = 1;
        }
    }

    vector<int> pre_sum(200001, 0);
    for (int i = 1; i <= 200000; ++i) {
        pre_sum[i] = pre_sum[i - 1] + v[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pre_sum[b] - pre_sum[a - 1] << endl;
    }
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
