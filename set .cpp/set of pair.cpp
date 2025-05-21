#include <bits/stdc++.h>
using namespace std;
int main(){
  set<pair <int, int >> s;

  s.insert({1 , 2});
  s.insert({2 , 3});
  s.insert({2 , 1});
  s.insert({2 , 1});
  s.insert({3 , 3});
  s.insert({3 , 4});
  s.insert({2 , 4});

  cout << s.size() << endl;
  for(auto u : s) cout << u.first << " " << u.second << endl;

  return 0;

}
