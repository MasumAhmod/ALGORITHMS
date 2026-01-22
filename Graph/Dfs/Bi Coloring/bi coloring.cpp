#include <bits/stdc++.h>
using namespace std;

#define N 500005
vector <int> adj[N];
int n , m;
int visited[N];
int color[N];
bool is_possible = true;

void dfs(int u ,  int c) {
    if(visited[u]) {
        if(color[u] == c) return;
        else {
            is_possible = false;
            return;
        }
    }

    visited[u] = 1;
    color[u] = c;

    for(int v :  adj[u]) {
        if(c == 1) {
            dfs(v , 2);
        } else {
            dfs(v , 1);
        }
    }
}

int main() {
    cin >> n >> m;

    for(int  i = 0; i < m; ++i) {
        int u , v;
        cin >> u >>  v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i) {
        if(visited[i]) continue;
        dfs(i , 1);
    }

    if(is_possible == false) {
        cout << "IMPOSSIBLE";
    } else {
        for(int i = 1; i <= n; ++i) {
            cout <<color[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

