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

long long isOk(vector<long long>& v, long long mid, long long x) {
    if (x <= v[mid - 1]) return 0;
    return 1;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> v;

    long long tmp = 0;

    long long k = n;

    while (n--) {
        long long a, b;
        cin >> a >> b;

        tmp += (a * b);
        v.push_back(tmp);
    }

    while (m--) {
        long long x;
        cin >> x;

        long long l = 1, r = k;

        while (l < r) {
            long long mid = (l + r) / 2;

            if (isOk(v, mid, x))
                l = mid + 1;
            else
                r = mid;
        }

        cout << l << endl;
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
