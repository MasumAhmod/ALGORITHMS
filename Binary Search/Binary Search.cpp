#include <bits/stdc++.h>
using namespace std;

// standard binary search
bool isOkStandard(vector <int> &v , int x , int mid)
{
    if(x >= v[mid]) return 0;

    return 1;
}

// upper_bound
bool isOkUpperBound(vector <int> &v , int x , int mid)
{
    if(x >= v[mid]) return 0;

    return 1;
}

//lower_bound
bool isOkLowerBound(vector <int> &v , int x , int mid)
{
    if(x > v[mid]) return 0;

    return 1;
}

int main() {
    vector<int> v = {2, 3, 5, 7, 10, 14, 14, 14, 17, 19};

    int key;
    cout << "Enter the key: ";
    cin >> key;

    int option;
    cout << "Choose search type (1 for Standard, 2 for Upper Bound, 3 for Lower Bound): ";
    cin >> option;

    int l = 0, r = v.size();

    switch(option) {
        case 1: {
            // Standard Binary Search
            while (l < r) {
                int mid = (l + r) / 2;
                if (isOkStandard(v, key, mid) == 0) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }

            if(key == v[l - 1]){
              cout << l << endl;
            } else {
              cout << "This value is not present in this list " << endl;
            }

            break;
        }
        case 2: {
            // Upper Bound Search
            while (l < r) {
                int mid = (l + r) / 2;
                if (isOkUpperBound(v, key, mid) == 0) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            cout << l + 1 << endl;
            break;
        }
        case 3: {
            // Lower Bound Search
            while (l < r) {
                int mid = (l + r) / 2;
                if (isOkLowerBound(v, key, mid) == 0) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            cout << l << endl;
            break;
        }
        default:
            cout << "Invalid option" << endl;
            break;
    }

    return 0;
}
