///MAsum
#include <bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'

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

void solve() {
    int x , y , z;
    cin >> x >> y >> z;

    string a = to_binary(x);
    string b = to_binary(y);
    string c = to_binary(z);

    int sz = max({a.size() , b.size() , c.size()});

    if(a.size() < sz) {
        int diff = sz - a.size();
        reverse(a.begin() , a.end());
        for(int i = 0; i < diff; ++i) {
            a += '0';
        }
        reverse(a.begin() , a.end());
    }

    if(b.size() < sz) {
        int diff = sz - b.size();
        reverse(b.begin() , b.end());
        for(int i = 0; i < diff; ++i) {
            b += '0';
        }
        reverse(b.begin() , b.end());
    }

    if(c.size() < sz) {
        int diff = sz - c.size();
        reverse(c.begin() , c.end());
        for(int i = 0; i < diff; ++i) {
            c += '0';
        }
        reverse(c.begin() , c.end());
    }

    string aa = "";
    for(int i = 0; i < sz; ++i) {
        if(a[i] == '1' || c[i] == '1') {
            aa += '1';
        } else {
            aa += '0';
        }
    }

    string bb = "";

    for(int i = 0; i < sz; ++i) {
        if(a[i] == '1' || b[i] == '1') {
            bb += '1';
        } else {
            bb += '0';
        }
    }

    string cc = "";
    for(int i = 0; i < sz; ++i) {
        if(b[i] == '1' || c[i] == '1') {
            cc += '1';
        } else {
            cc += '0';
        }
    }

    long long aaa = to_decimal(aa) , bbb = to_decimal(bb) , ccc = to_decimal(cc);
    if(((aaa & bbb) == x) && ((bbb & ccc) == y) && ((ccc & aaa) == z)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    Start

    int t = 0;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

