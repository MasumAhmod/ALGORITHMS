
///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'

long long allOnes(long long x) {
    long long cnt = 0;

    while(x) {
        if(x & 1) {
            cnt++;
        }

        x /= 2;
    }
    return cnt;
}

void solve()
{
    long long n , k;
    cin >> n >> k;

    vector <long long> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for(int bit = 0; bit <= 60; ++bit) {
        for(auto &u : v) {
            if((u >> bit) & 1) {
                continue;
            }

            long long curr = (1LL << bit);
            if(curr <= k) {
                u += curr;
                k -= curr;
            }
        }
    }

    long long ans = 0;
    for(auto  &u : v) {
        ans += allOnes(u);
    }

    cout << ans << endl;
}

int32_t main()
{
    ///cODE BY Masum
    optimize();

    // solve();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
