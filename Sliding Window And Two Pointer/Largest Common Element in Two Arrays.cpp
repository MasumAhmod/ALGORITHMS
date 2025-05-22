///Masum
#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define gcd __gcd
#define MOD 1000000007

void solve()
{
    int n , m;
    cin >> n >> m;

    vector<int> a(n) , b(m);
    for(auto &u : a) cin >> u;

    for(auto &u : b){
        cin >> u;
    }

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    int mx = -1;
    int i = 0 , j = 0;
    while(1){
        if(a[i] == b[j]){
            mx = max(mx , a[i]);

            i++;
            j++;
        } else if(a[i] < b[j]){
            i++;
        } else {
            j++;
        }

        if(i >= n || j >= m){
            break;
        }
    }

    cout << mx << endl;
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



