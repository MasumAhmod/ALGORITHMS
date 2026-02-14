///MAsum
#include <bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vii vector<long long>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define gcd __gcd
#define vall v.begin(),v.end()
#define MOD 1000000007

const int mx = 6e3 + 123;
int par[mx];
int n;

void init() {
    for(int i = 1; i <= 2 * n; ++i) {
        par[i] = i;
    }
}

int find(int i) {
    if(par[i] == i) {
        return i;
    }

    return par[i] = find(par[i]);
}

bool dsu_join(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if(pa == pb) {
        return false;
    }

    par[pb] = pa;
    return true;
}

void solve()
{
    cin >> n;

    init();

    vector <int> ans;

    for(int i = 1; i <= n; ++i) {
        int a , b;
        cin >>a >> b;

        if(dsu_join(a , b)) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(auto &u : ans) {
        cout << u << " ";
    } cout << endl;

}

int32_t main()
{
    Start

    int t = 0;
    cin >> t;

    // solve();

    while (t--)
    {
        solve();
    }

    return 0;
}