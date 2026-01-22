/// find maximum gcd
/// remove / change one element and find maximum gcd

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

int main()
{
    int n ;
    cin >> n;

    vector <int> v(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }

    vector <int> prefix_gcd(n + 2);
    prefix_gcd[0] = 0;

    for(int i = 1; i <= n; ++i){
        prefix_gcd[i] = gcd(prefix_gcd[i - 1] , v[i]);
    }

    vector <int> suffix_gcd(n + 2);
    suffix_gcd[n + 1] = 0;

    for(int i = n; i >= 1; --i){
        suffix_gcd[i] = gcd(suffix_gcd[i + 1] , v[i]);
    }

    int mx = 0;

    for(int i = 1; i <= n; ++i){
        mx = max(mx , gcd(prefix_gcd[i - 1] , suffix_gcd[i + 1]));
    }
    cout << mx << endl;
}
