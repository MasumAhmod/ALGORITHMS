///Masum
///Activity selection
#include <bits/stdc++.h>

using namespace std;

struct activity {
    int start;
    int endd;
};

bool comp(activity p, activity q) {
    return p.endd < q.endd;
}

int main() {
    int n = 5;
    activity a[n];

    for(int i = 0; i < n; ++i){
      cin >> a[i].start;
      cin >> a[i].endd;
    }

    sort(a, a + n, comp);

    cout << a[0].start << " " << a[0].endd << endl;
    int currentEnd = a[0].endd;

    for (int i = 1; i < n; ++i) {
        if (currentEnd <= a[i].start) {
            cout << a[i].start << " " << a[i].endd << endl;
            currentEnd = a[i].endd;
        }
    }
}

