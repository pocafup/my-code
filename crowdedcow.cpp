#include <iostream>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

pair<int,int> pos[100001];
int main(){
  int a,b; cin >> a >> b;
  int ans = 0;
  for (int i=0;i<a;i++) cin >> pos[i].first >> pos[i].second;
  sort(pos,pos+a);
  set<int> left,right;
  int le = 0, ri = 2;
  left.insert(pos[0].second);
  right.insert(pos[2].second);
  int begin = 1;
  while(begin<a){
    left.insert(pos[begin].second);
    while(pos[begin].first-pos[le].first>b) {
      left.erase(pos[le].second);
      le++;
    }
    right.erase(pos[begin].second);
    while(pos[ri].first-pos[begin].first){
      if (ri==a) break;
      right.insert(pos[ri].second);
      ri++;
    }
    auto i1 = left.lower_bound(pos[begin].second*2);
    auto i2 = right.lower_bound(pos[begin].second*2);
    if (*i1>0 && *i2>0 && *i1<30000 && *i2<30000) ans++;
    cout << *i1 << " " << *i2 << endl;
    begin++;
    if (begin == ri && ri!=a){
      ri++;
    }
  }
  cout << ans;
}
