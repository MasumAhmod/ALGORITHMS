///Masum
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    long long n;
    cin >> n;

    vector <long long> v(n);

    vector <long long> cnt_0(30) , cnt_1(30);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    long long mx = -1;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 30; ++j) {
            if(v[i] & (1LL << j)) {
                cnt_1[j]++;
            } else {
                cnt_0[j]++;
            }
        }
    }

    for(int i = 0; i < n; ++i) {

        long long ans = 0;

        for(int j = 0; j < 30; ++j) {

            if(v[i] & (1LL << j)) {
                long long tmp = cnt_0[j];

                ans += (tmp * (1LL << j));
            } else {
                long long tmp = cnt_1[j];

                ans += (tmp * (1LL << j));
            }
        }

        mx = max(mx , ans);
    }

    cout << mx << endl;
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
