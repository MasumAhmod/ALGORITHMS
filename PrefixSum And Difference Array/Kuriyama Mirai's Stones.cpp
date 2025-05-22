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
    int n;
    cin >> n;

    vector <long long> v(n + 1) , pre(n + 1 , 0) , pre1(n + 1 , 0);
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }

    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1] + v[i];
    }

    vector <long long> u(n + 1);
    u = v;
    sort(u.begin() , u.end());


    for(int i = 1; i <= n; ++i){
        pre1[i] = pre1[i - 1] + u[i];
    }

    int m;
    cin >> m;
    while(m--){
        int t , l , r;
        cin >> t >> l >> r;

        if(t == 1){
            long long ans = pre[r] - pre[l - 1];

            cout << ans << endl;
        } else if(t == 2){
            long long ans = pre1[r] - pre1[l - 1];

            cout << ans << endl;
        }
    }
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

 
