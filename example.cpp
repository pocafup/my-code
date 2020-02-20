#include <iostream>
#include <string>
#include <utility>
#include <set>
using namespace std;
int main(){
  int n; cin >> n;
  set<pair<int,int> > s;
  int ans = 0;
  for (int i=0;i<n;i++){
    int a,b,c,d; cin >> a >> b >> c >> d;
    pair<int,int> p1(a,b);
    pair<int,int> p2(a,d);
    pair<int,int> p3(c,b);
    pair<int,int> p4(c,d);
    auto it1 = s.find(p1), it2 = s.find(p2) , it3 = s.find(p3), it4 = s.find(p4);

    if (it1==s.end() && it2==s.end() && it3 == s.end() && it4 == s.end()) ans++;
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    // if (it1==s.end() && it2==s.end() && it3==s.end() && it4 = s.end()) ans++;

    // cout << it->first << "," << it->second <<endl;

  }
  cout << ans;
  // pair<int,int> p1(1,0);
  // pair<int,int> p2(2,1);

}
