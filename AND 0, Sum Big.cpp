///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ssort(s) sort(s.begin(), s.end())
#define vsort(v) sort(v.begin(), v.end())
#define sunique(s) s.erase(unique(s.begin(), s.end()), s.end())
#define vunique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define ll long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vii vector<long long>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define gcd __gcd
#define MOD 1000000007

ll power(ll base , ll p)
{
    ll ans = 1;
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
    ll n , k;
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
