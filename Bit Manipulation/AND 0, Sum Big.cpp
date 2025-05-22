///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

long long power(long long base , long long p)
{
    long long ans = 1;
    base = base % MOD;
    while(p) {
        if(p % 2 == 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        p /= 2;
    }
    return ans % MOD;
}

void solve() {
    long long n , k;
    cin >> n >> k;

    cout << power(n , k) << endl;
}

int32_t main()
{
    optimize();

    ///solve();

     int t;
     cin >> t;

     while (t--)
     {
         solve();
     }

    return 0;
}
