#include <bits/stdc++.h>
using namespace std;
int main(){
  set <int> s = {1, 2 , 3 , 3, 0 , 2};

  s.clear();
  cout << s.empty() << endl; /// it will return bool data type .. 1 means true

  s.insert(2);
  s.insert(5);
  s.insert(3);
  s.insert(2);
  s.insert(1);
  cout << s.size() << endl;
  for(auto u : s) cout << u << " ";
  cout << endl;

  cout << "2 occur in set is : " << s.count(2) << endl; /// after unique it will show an element is in set or not

  s.erase( 2 );
  for(auto u : s) cout << u << " ";
  cout << endl;
  return 0;
}

