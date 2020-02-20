#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>

using namespace std;
#define pp pair<int,int>
vector<pp> vec[25000][4];
int main(){
  int n; cin >> n;
  set<pp> se;
  int ans = 0;

  for (int i=0;i<n;i++){
    int a,b,c,d; cin >> a >> b >> c >> d;
    // vec[i][0].push_back(make_pair(a,b));
    // vec[i][1].push_back(make_pair(a,d));
    // vec[i][2].push_back(make_pair(c,b));
    // vec[i][3].push_back(make_pair(c,d));
    if ((se.find(make_pair(a,b)==se.end())) &&
         se.find(make_pair(a,d)==se.end() &&
         se.find(make_pair(c,b)==se.end() &&
         se.find(make_pair(c,d)==se.end())))) ans++;
    se.insert(make_pair(a,b));
    se.insert(make_pair(a,d));
    se.insert(make_pair(c,b));
    se.insert(make_pair(c,d));
  }
  // for (int i=0;i<n;i++){
  //   bool update = true;
  //   for (int j=0;j<4;j++){
  //     multiset<pp>::iterator it = se.find(pair(vec[i][j].first,vec[i][j].second));
  //     se.erase(it);
  //     if (se.find(vec[i][j])!=se.end()) {update = false; break;}
  //   }
  //   if (update) ans++;
  // }
  cout << ans;
}
