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

void solve()
{
    long long n , x;
    cin >> n >> x;

    if(n == 1){
        if(x == 0){
            cout << -1 << endl;
        } else {
            cout << x << endl;
        }
        return;
    }

    if(x == 0){

        if(n & 1){
            ///for n = 3 always ans will be 6
            if(n == 3){
                cout << 6 << endl;
            } else {
                int tmp = n - 3;
                cout << 6 + tmp << endl;
            }
        } else {
            cout << n << endl;
        }
        return;
    }

    if(x == 1){
        if(n & 1){
            /// we'll place even no of 1
            cout << n << endl;
        } else {
            ///for n = 2 we can get sum 5 , for rest of n we'll add just n - 2
            int tmp = n - 2;
            cout << (5 + tmp) << endl;
        }
        return;
    }

    long long cnt = 0;

    ///count how many set bit in x
    for(int i = 0; i < 30; ++i){
        if((1LL << i) & x){
            cnt++;
        }
    }

    if(n <= cnt){
        cout << x << endl;
        return;
    }

    n -= cnt;

    if(n & 1){
        x += (n + 1);
        cout << x << endl;
    } else {
        cout << (n + x) << endl;
    }
}


int32_t main()
{
    optimize();

    //solve();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
 
