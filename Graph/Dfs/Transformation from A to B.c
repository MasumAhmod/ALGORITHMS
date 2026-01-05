///MAsum
n#include <bits/stdc++.h>
using namespace std;

long long a , b;
bool possible = false;

map <long long , long long> previous_number;

void dfs(long long n , long long prev) {
    if(n > b) {
        return;
    }

    previous_number[n] = prev;

    if(n == b) {
        possible = true;
        return;
    }

    dfs(2 * n , n);
    dfs((10 * n) +  1 , n);
}

int main() {
    cin >> a >> b;

    dfs(a , 0);

    if(possible) {
        cout << "YES" << endl;

        vector <long long> seq;
        int n = b;

        while(1) {
            seq.push_back(n);
            n = previous_number[n];

            if(n == a) {
                break;
            }
        }
        seq.push_back(a);

        reverse(seq.begin() , seq.end());
        cout << seq.size() << endl;

        for(auto &u : seq) {
            cout << u << ' ';
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
