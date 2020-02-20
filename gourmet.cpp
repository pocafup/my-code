#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;
#define pp pair<long long,long long>
bool sorted(pp a, pp b){
  if (a.second!=b.second) return a.second>b.second;
  return a.first>b.first;
}
pp cow[100001];
pp spent[100001];
int main(){
  long long a,b; cin >> a >> b;
  for (long long i=0;i<a;i++) cin >> cow[i].first >> cow[i].second;
  for (long long i=0;i<b;i++) cin >> spent[i].first >> spent[i].second;
  sort(cow,cow+a,sorted);
  sort(spent,spent+b,sorted);
  multiset<long long> se;
  long long pos = 0,curr = 0;
  long long ans = 0;
  // for (long long i=0;i<b;i++){
  //   cout << "spent " << i << " = " << spent[i].first << " " << spent[i].second << endl;
  // }
  // for (long long i=0;i<a;i++){
  //   cout << "cow " << i << " = " << cow[i].first << " " << cow[i].second << endl;
  // }
  while(pos<a){
    while(cow[pos].second<=spent[curr].second && curr<b){
      se.insert(spent[curr].first);
      curr++;
    }
    multiset<long long>::iterator it = se.lower_bound(cow[pos].first);
    ans += (*it);
    se.erase(se.find(*it));
    pos++;
  }
  cout << ans;
}
