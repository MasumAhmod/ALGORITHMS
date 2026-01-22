/// Masum
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    long long n , x;
    cin >> n >> x;

    vector <long long> v(n);
    for(int i = 0; i < n; ++i) {
        v[i] = i;
    }

    for(auto &u : v) {
        for(int i = 0; i < 30; ++i) {
            if(u & (1LL << i)) {
                if(x & (1LL << i)) continue;

                u -= (1LL << i);
            }
        }
    }

    long long chk = v[0];
    for(int i = 1; i < n; ++i) {
        chk |= v[i];
    }

    if(chk != x) {
        v[n - 1] = x;
    }

    for(auto &u : v) {
        cout << u << " ";
    }
    cout << endl;
}

int32_t main()
{
    ///cODE BY Masum
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // solve();

    int t;
    cin >> t;

    while (t--){

        solve();
    }

    return 0;
}
