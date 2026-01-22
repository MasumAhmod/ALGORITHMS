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

void solve() {
    int n;
    cin >> n;

    string s = to_binary(n);

    int cnt = 0;

    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '1') {
            cnt++;
        }
    }

    if(cnt & 1) {
        cout << "NO" << endl;
        return;
    }

    bool chk = true;

    int m = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        if(s[i] == '0') {
            m++;
        } else {
            break;
        }
    }

    string t = "";
    for(int i = 0; i < (s.size() - m); ++i) {
        t += s[i];
    }

    int tmp = t.size();

    for(int i = 0; i < ((tmp / 2) + 1); ++i) {
        if(t[i] != t[tmp - i - 1]) {
            chk = false;
            break;
        }
    }

    if(chk) {
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

