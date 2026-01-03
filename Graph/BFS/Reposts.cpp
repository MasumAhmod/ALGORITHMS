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

const int mx = 200000 + 5;

vector<int> g[mx];
int lev[mx];
map <string , int> id;
int idx = 0;

// bfs don't work with strings , so i put a number against that  string
int get_id(string s)
{
    if (!id.count(s)) {
        idx++;
        id[s] = idx;
    }
    return id[s];
}

void bfs(int s)
{
    for (int i = 1; i <= idx; ++i) {
        lev[i] = -1;
    }

    queue <int> q;
    lev[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (lev[v] == -1) {
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    while (n--) {
        string a, tmp, b;
        cin >> a >> tmp >> b;

        for (char &c : a) c = tolower(c);
        for (char &c : b) c = tolower(c);

        int u = get_id(a);
        int v = get_id(b);

        g[v].push_back(u);
        g[u].push_back(v);
    }

    int start = get_id("polycarp");
    bfs(start);

    int ans = 0;
    for (int i = 1; i <= idx; ++i) {
        ans = max(ans, lev[i]);
    }

    cout << ans + 1 << endl;
}

int32_t main()
{
    Start

    int t = 0;
    //cin >> t;

    solve();

    while (t--)
    {
        solve();
    }

    return 0;
}

