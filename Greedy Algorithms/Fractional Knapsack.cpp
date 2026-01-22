///Masum
/// Fractional knapsack
#include <bits/stdc++.h>

using namespace std;

struct item {
    int profit;
    int weight;
    double ratioo;
};

bool comp(item p, item q) {
    return p.ratioo > q.ratioo;
}

int main() {
    int n = 5;
    int cap = 8;

    item a[n];

    for(int i = 0; i < n; ++i){
      cin >> a[i].profit;
      cin >> a[i].weight;

      a[i].ratioo = (double)a[i].profit / (double)a[i].weight;
    }

    sort(a, a + n, comp);

    double totalProfit = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i].weight < cap){

            totalProfit += a[i].profit;
            cap -= a[i].weight;

        } else {
            totalProfit += (cap * a[i].ratioo);
            break;
        }
    }
    cout << totalProfit << endl;

}

