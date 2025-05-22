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

void solve()
{
    int n;
    cin >> n;

    vi a(n) , b(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    int cnt = 0;
    int i = 0 , j = 0;
    while(1){
        if(a[i] == b[j]){
            cnt++;
            i++;
            j++;
        } else if(a[i] < b[j]){
            i++;
        } else {
            j++;
        }

        if(i >= n || j >= n){
            break;
        }
    }
    cout << cnt << endl;
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



