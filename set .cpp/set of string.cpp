#include <bits/stdc++.h>
using namespace std;
int main(){
  set <string> s ;
  s.insert("masum");
  s.insert("mumu");
  s.insert("shashy");
  s.insert("sumit");
  s.insert("tusar");

  s.insert("masum");
  s.insert("mumu");
  s.insert("shashy");
  s.insert("sumit");
  s.insert("tusar");

  cout << s.size() << endl;
  for(auto u : s) cout << u << " ";
  cout << endl;
  return 0;

}
