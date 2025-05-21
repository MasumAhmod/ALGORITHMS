///Masum
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
#define MOD 1000000007

long long isOk(long long x , long long n , long long k){
    long long tmp = x - (x / n);

    if(tmp < k) return 0;
    return 1;
}

void solve() {
    long long n , k;
    cin >> n >> k;

    long long l = 1 , r = 2 * k + 1;
    while(l < r){
        long long mid = (l + r) / 2;

        if(isOk(mid , n , k) == 0) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
}

int32_t main()
{
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
