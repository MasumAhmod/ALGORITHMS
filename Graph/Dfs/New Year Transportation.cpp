#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define vi vector<int>

const int mx = 5e5 + 123;
vi adj[mx];
int lev[mx];

void bfs(int s)
{
    memset(lev, -1, sizeof(lev));

    lev[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (lev[v] == -1) {
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for(int i = 1; i < n; ++i) {
        int u;
        cin >> u;
        adj[i].push_back(i + u);
    }

    bfs(1);

    if(lev[k] != -1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

