/// CODE BY Masum
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
#define MOD 998244353

void solve() {
    long long n;

    cin >> n;

    if(n == 2){
        cout << 0 << endl;
        return;
    }

    if(n == 3 || n == 4){
        cout << 1 << endl;
        return;
    }

    long long last_val = -1 , tmp;
    for(int i = 0; i < 30; ++i){
        tmp = (1ll << i);

        if(tmp <= n){
            last_val = i;
        }
    }


    long long ans = 0;
    for(int i = 1; i < last_val; ++i){
        ans += (1ll << i) - 1;
    }

    long long m = n - (1 << last_val);
    ans += m;

    cout << ans << endl;
}


int32_t main() {
    optimize();

    //solve();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}


