#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    int n;
    cin >> n;

    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        s.insert(k);
    }

    if (s.size() == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;

    return 0;
}
