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
#define MOD 998244353

string to_binary(long long n) {

    string binary;

    if(n == 0) return "0";
    while(n > 0) {

        binary = (n % 2ll == 0 ? "0" : "1") + binary;

        n /= 2ll;
    }
    return binary;
}

long long to_decimal(const string& binary) {

    long long n = binary.size() - 1;

    string s = binary;

    reverse(s.begin(), s.end());

    int base = 1;

    long long decimal = 0;

    for(int i = n; i >= 0; --i) {
        if(s[i] == '1') {
            decimal += (base * (1LL << i));
        }
    }
    return decimal;
}

void solve()
{
    long long n;
    cin >> n;

    if(n > 0 && (n & (n - 1)) == 0){
        cout << 1 << endl;
        cout << n << endl;
        return;
    }

    string s = to_binary(n);
    long long dec = to_decimal(s);

    // cout << s << endl;
    // cout << dec << endl;

    set <long long> st;
    st.insert(dec);

    for(int i = 0; i < s.size(); ++i) {
        string t = s;
        reverse(t.begin(), t.end());

        if(t[i] == '1') {
            t[i] = '0';
        }

        reverse(t.begin(), t.end());
        st.insert(to_decimal(t));
    }

    cout << st.size() << endl;

    for (auto u : st) {
        cout << u << " ";
    }
    cout << endl;
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
