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
    long long n , k;

    cin >> n >> k;

    if(n == 1){
        cout << k << endl;
        return;
    }

    long long last_val = -1 , tmp;
    for(int i = 0; i < 30; ++i){
        tmp = (1ll << i);

        if(tmp - 1 < k){
            last_val = tmp - 1;
        }
    }

    cout << last_val << " ";

    long long remining = k - last_val;
    cout << remining << " ";

    int m = n - 2;

    for(int i = 0; i < m; ++i){
        cout << 0 << " ";
    }
    cout << endl;
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
 
