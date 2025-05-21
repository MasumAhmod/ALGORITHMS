#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        int ans = *max_element(v.begin(), v.end());
        for (int i = 1; i < n; i++) {
            if (v[i - 1] > v[i]) {
                ans = 0;
                break;
            } else {
                int m = (v[i] - v[i - 1]) / 2 + 1;
                ans = min(ans , m);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
