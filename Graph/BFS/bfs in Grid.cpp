/// CODE BY Masum
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

const int mx = 1e3 + 5;
int n, m;
vector < vector <char>> adj(mx, vector <char>(mx));
vector < vector <bool>> vis(mx, vector <bool>(mx, false));

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    vis[a][b] = true;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        int x = u.first;
        int y = u.second;

        for (int i = 0; i < 4; ++i) {
            int r = x + dx[i];
            int c = y + dy[i];

            if (r >= 0 && r < n && c >= 0 && c < m) {
                if (adj[r][c] == '.' && !vis[r][c]) {
                    q.push({r, c});
                    vis[r][c] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> adj[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && adj[i][j] == '.') {
                cnt++;
                bfs(i, j);
            }
        }
    }

    cout << cnt << endl;
    return 0;
}

