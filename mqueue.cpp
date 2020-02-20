#include <iostream>
#include <algorithm>
using namespace std;
pair<pair<int,int>,int> pos[25001];
bool sorted(pair<pair<int,int>,int> aa,pair<pair<int,int>,int> bb){
  return aa.second<bb.second;
}
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) {
    cin >> pos[i].first.first >> pos[i].first.second;
    if (pos[i].first.first<pos[i].first.second) pos[i].second = pos[i].first.first;
    else pos[i].second = 1e8-pos[i].first.second;
  }

  // for (int i=0;i<a;i++) cout << pos[i].first << " " << pos[i].second << endl;

  sort(pos,pos+a,sorted);
  int now = pos[0].first.second;
  int ans = pos[0].first.first;
  for (int i=1;i<a;i++){
    ans += pos[i].first.first;
    now = now-pos[i].first.first<0 ? 0 : now-pos[i].first.first;
    now+= pos[i].first.second;
  }
  cout << ans+now;
}
