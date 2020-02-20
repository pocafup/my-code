#include <iostream>
#include <algorithm>
#include <set>
#include <fstream>
#include <iterator>
using namespace std;
#define pp pair<int,int>
pp cow[100005];
int chick[100005],n,m,ans = 0;
bool sorted(pp a, pp b){
  return a.first<b.first;
}
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

bool between(int a, pp b){
  return a>=b.first &&a<=b.second;
}
multiset<int> se;
int main(){
  setIO("helpcross");
  cin >> n >> m;
  for (int i=0;i<n;i++) cin >> chick[i];
  for (int i=0;i<m;i++){
    cin >> cow[i].first >> cow[i].second;
  }
  sort(chick,chick+n);
  sort(cow,cow+m,sorted);
  int pt = 0;
  for(int i=0;i<n;i++){
    if (pt<m) while (chick[i]>=cow[pt].first && pt<m){se.insert(cow[pt].second);pt++; if (pt>=m) break;}
    if (se.size()){
      multiset<int>::iterator it = se.lower_bound(chick[i]);

      if (se.find(*it)!=se.end()) {se.erase(it);ans++;}
    }
  }
  cout << ans;
}
