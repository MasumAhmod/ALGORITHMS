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
    string s;
    cin >> s;

    int n = s.size();

    unordered_map <char , int> mp;
    int mx_char = 0;

    deque <char> dq;

    for(int i = 0; i < n; ++i){
        if(mp[s[i]] == 1){
            while(1){
                auto ch = dq.front();

                dq.pop_front();
                mp[ch] = 0;

                if(ch == s[i]){
                    break;
                }
            }
        }

        dq.push_back(s[i]);
        mp[s[i]] = 1;

        int m = dq.size();

        mx_char = max(mx_char , m);
    }
    cout << mx_char << endl;
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



