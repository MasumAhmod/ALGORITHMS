///Masum
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
    long long n;
    cin >> n;

    vector <long long> v(n);
    for(int i = 0; i < n; ++i) {

        cin >> v[i];
    }

    long long mn = -1, mx = -1;
    long long l = 0, r = n - 1;

    while(l <= r) {

        if(mn == -1 && mx == -1) {

            if(v[l] < v[r]) {

                l++;
                mn = 1;

                cout << "L";
            }
            else {

                r--;
                mx = 1;

                cout << "R";
            }
        } else if (mn == -1) {

            if(v[l] < v[r]) {

                l++;
                cout << "L";
            }
            else {

                r--;
                cout << "R";
            }

            mn = 1;
            mx = -1;
        } else {
            if(v[l] < v[r]) {

                r--;
                cout << "R";
            } else {

                l++;
                cout << "L";
            }

            mn = -1;
            mx = 1;
        }
    }
    cout << endl;
}

int32_t main()
{
    /// CODE BY Masum
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // solve();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
