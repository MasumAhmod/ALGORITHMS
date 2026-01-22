///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'

long long isOk(long long mid, long long x , const vector<long long> &v)
{
    if (v[mid] <= x) return 0;
    else return 1;
}

void solve()
{
    long long n, m;
    cin >> n >> m;

    vector<long long> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    while(m--){
        long long x;
        cin >> x;

        long long l = 0, r = n;
        while(l < r){
            long long mid = (l + r) / 2;

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
