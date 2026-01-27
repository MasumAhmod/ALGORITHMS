///MAsum
#include <bits/stdc++.h>
using namespace std;

///Iterative DFS

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

const int mx = 2e5 + 5;
int n;
vector <pair <int , int>> g[mx];
int ans[mx];

void dfs_iterative(int u) {
    stack < tuple <int , int, int>> st;
    st.push({1 , -1 , 0});

    while(!st.empty()) {
        auto [u , p , pi] = st.top(); //node , parent, index
        st.pop();

        for(auto [v , i] : g[u]) {
            if(v == p) continue;

            if(i > pi) {
                ans[i] = ans[pi];
            } else {
                ans[i] = ans[pi] + 1;
            }

            st.push({v , u , i});
        }
    }
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        g[i].clear();
    }

    for(int i = 1; i < n; ++i) {
        int u , v;
        cin >> u >> v;

        g[u].push_back({v , i});
        g[v].push_back({u , i});
    }

    ans[0] = 1;
    dfs_iterative(1);

    int mx = 1;
    for(int i = 1; i < n; ++i) {
        mx = max(mx , ans[i]);
    }

    cout << mx << endl;
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

///Recursive DFS
// #include <bits/stdc++.h>
// using namespace std;

// #define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long
// #define endl '\n'
// #define pb push_back
// #define vi vector<int>
// #define vii vector<long long>
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define gcd __gcd
// #define vall v.begin(),v.end()
// #define MOD 1000000007

// const int mx = 2e5 + 5;
// int n;
// vector <pair <int , int>> g[mx];
// int ans[mx];

// void dfs(int u , int p, int pi) {
//     for(auto [v , i] : g[u]) {
//         if(v == p) continue;

//         if(i > pi) {
//             ans[i] = ans[pi];
//         } else {
//             ans[i] = ans[pi] + 1;
//         }

//         dfs(v, u, i);
//     }
// }

// void solve()
// {
//     cin >> n;
//     for(int i = 1; i <= n; ++i) {
//         g[i].clear();
//     }

//     for(int i = 1; i < n; ++i) {
//         int u , v;
//         cin >> u >> v;

//         g[u].push_back({v , i});
//         g[v].push_back({u , i});
//     }

//     ans[0] = 1;
//     dfs(1 , -1 , 0);

//     int mx = 1;
//     for(int i = 1; i < n; ++i) {
//         mx = max(mx , ans[i]);
//     }

//     cout << mx << endl;
// }

// int32_t main()
// {
//     Start

//     int t = 0;
//     cin >> t;

//     // solve();

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }
