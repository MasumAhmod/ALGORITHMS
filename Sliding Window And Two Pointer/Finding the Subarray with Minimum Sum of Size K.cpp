///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'

void solve()
{
    int n , k;
    cin >> n >> k;

    vector<int> v(n);
    for(auto &u : v) cin >> u;

    long long sum = 0;

    multiset <int> ms;
    for(int i = 0; i < k; ++i){
        ms.insert(v[i]);

        sum += v[i];
    }

    long long mn = sum;
    for(int i = 0; i < n; ++i){
        if(i + k < n){
            sum += v[i + k] - v[i];
        }

        mn = min(mn , sum);
    }
    cout << mn << endl;
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



