#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

pair<int,int> rain[100001];
int main(){
  int a,b; cin >> a >> b;
  multiset<pair<int,int> > se;
  for (int i=0;i<a;i++) cin >> rain[i].first >> rain[i].second;
  sort(rain,rain+a);
  int str = 0;
  int ans = 1e8;
  while(str!=a-1){
    int en = str+1;
    bool check = false;
    while(abs(rain[en].second-rain[str].second)<b && !check) {
      se.insert(rain[en]);
      en++;

      if (en == a-1) {check = true;break;}
    }
    if (!check && se.size()){
      multiset<pair<int,int> >::iterator it = se.lower_bound(make_pair(rain[str].first,rain[str].second+b));
      multiset<pair<int,int> >::iterator it2 = se.upper_bound(make_pair(rain[str].first,rain[str].second-b));
      if ((*it).first!=0) {
        ans = min(ans,abs(rain[str].second-(*it).second));
      }
      if ((*it2).first!=0) ans = min(ans,abs(rain[str].second-(*it2).second));
    }
    if (se.size()){
      if (se.find(rain[str]).first!=0){
        se.erase(se.find(rain[str]));
      }
    }
    //if (se.size() && se.find(rain[str])) se.erase(se.find(rain[str]));
    str++;
  }
  cout << ans;
}
