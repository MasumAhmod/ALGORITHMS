///MAsum
#include <bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'

string to_binary(long long n)
{

    string binary;

    if(n == 0) return "0";
    while(n > 0)
    {

        binary = (n % 2ll == 0 ? "0" : "1") + binary;

        n /= 2ll;
    }
    return binary;
}

long long to_decimal(const string& binary)
{

    long long n = binary.size() - 1;

    string s = binary;

    reverse(s.begin(), s.end());

    int base = 1;

    long long decimal = 0;

    for(int i = n; i >= 0; --i)
    {
        if(s[i] == '1')
        {
            decimal += (base * (1LL << i));
        }
    }
    return decimal;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    if(a == b)
    {
        cout << 0 << endl;
        return;
    }

    if(a > b)
    {
        cout << 2 << endl;
        string s = to_binary(a);
        string t = "";

        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '0')
            {
                t += '1';
            }
            else
            {
                t += '0';
            }
        }

        int m = to_decimal(t);
        cout << m << " ";

        t = "";
        string ss = "";
        for(int i = 0; i < s.size(); ++i)
        {
            ss += '1';
        }

        string p = to_binary(b);
        int q = s.size();

        if(q > p.size())
        {
            int tmp = q - p.size();
            reverse(p.begin(), p.end());

            for(int i = 0; i < tmp; ++i) p += '0';
            reverse(p.begin(), p.end());
        }

        string tt = "";
        for(int i = 0; i < q; ++i)
        {
            if(p[i] == '0')
            {
                tt += '1';
            }
            else
            {
                tt += '0';
            }
        }

        m = to_decimal(tt);
        cout << m << endl;
    }
    else
    {
        string n = to_binary(a);
        string m = to_binary(b);

        if(n.size() < m.size())
        {
            cout << -1 << endl;
        }
        else if(n.size() == m.size())
        {
            cout << 2 << endl;

            string t = "";

            for(int i = 0; i < n.size(); ++i)
            {
                if(n[i] == '0')
                {
                    t += '1';
                }
                else
                {
                    t += '0';
                }
            }

            int k = to_decimal(t);
            cout << k << " ";


            t = "";
            string ss = "";
            for(int i = 0; i < n.size(); ++i)
            {
                ss += '1';
            }

            string p = to_binary(b);
            int q = n.size();

            if(q > p.size())
            {
                int tmp = q - p.size();
                reverse(p.begin(), p.end());

                for(int i = 0; i < tmp; ++i) p += '0';
                reverse(p.begin(), p.end());
            }

            string tt = "";
            for(int i = 0; i < q; ++i)
            {
                if(p[i] == '0')
                {
                    tt += '1';
                }
                else
                {
                    tt += '0';
                }
            }

            k = to_decimal(tt);
            cout << k << endl;
        }
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

