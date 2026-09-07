///MAsum
#include <bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vii vector<long long>
#define yes cout << YES << endl
#define no cout << NO << endl
#define gcd __gcd
#define vall v.begin(),v.end()
#define MOD 1000000007

const int mx = 1e5 + 123;

vector <int> graph[mx];
multiset <int> ms;
int level[mx];

int rem = 0 , cnt = 0;

void bfs(int src) {
    memset(level, -1, sizeof(level));

    rem = 0;
    cnt = 0;

    level[src] = 0;

    queue <int> q;
    q.push(src);

        int u = q.front();
        q.pop();

        if(ms.count(u)) {
            cnt += ms.count(u);
            if(cnt == 1) {
                rem = u;
                break;
            }
        }

        for(auto &v : graph[u]) {
            if(level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {
    ms.clear();
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        graph[i].clear();
    }

    for(int i = 2; i <= n; ++i) {
        int u;
        cin >> u;

        graph[u].push_back(i);
        graph[i].push_back(u);
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        ms.insert(x);
    }

    bfs(1);
    
    cout << m-1 <<  ;
    for(auto &u : ms) {
        if(u == rem) {

        } else {
            cout << u <<  ;
        }
    }
    cout << endl;
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
