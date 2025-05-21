///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

long long req(long long x , long long n , vector <long long> &v){
    long long totsum = 0;

    for(int i = n / 2; i < n; ++i){
        if (v[i] < x) totsum += (x - v[i]);
    }
    return totsum;
}

long long isOk(long long x , long long k , long long n , vector <long long> &v){
    if(req(x , n , v) > k) return 1;
    return 0;
}

void solve() {
    long long n , k;
    cin >> n >> k;

    vector <long long> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    sort(v.begin() , v.end());

    long long l = 0 , r = 1e9 + 1 + k;
    while(l < r){
        long long mid = (l + r) / 2;

        if(isOk(mid , k , n , v) == 0) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << endl;
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
