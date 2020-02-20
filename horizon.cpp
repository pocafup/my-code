#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
pair<pair<long long,long long>,long long> pos[40001];
pair<pair<long long,long long>,long long> arr[40001];
bool sorted(pair<pair<long long,long long>,long long> aa, pair<pair<long long,long long>,long long> bb){
  if (aa.first.first<bb.first.first) return true;
  if (aa.first.first>bb.first.first) return false;
  if (aa.second>bb.second) return true;
  return false;
}
int main(){
  long long a; cin >> a;
  multiset<long long,greater<long long> > se;
  for (long long i=0;i<a;i++) {
    long long c,d,e; cin >> c >> d >> e;
    arr[i*2] = make_pair(make_pair(c,e),1);
    arr[i*2+1] = make_pair(make_pair(d,e),-1);
  }
  sort(arr,arr+2*a,sorted);
  // for (long long i=0;i<a;i++) cout << arr[i].first.first << " " << arr[i].first.second << " " << arr[i].second << endl;
  long long ans = 0;
  long long prefix = 0;
  long long prev = 0;
  for (long long i=0;i<a*2;i++){
    long long af = arr[i].first.first;
    long long as = arr[i].first.second;
    long long ad = arr[i].second;
    // cout << "       " << af << endl;
    // cout << prev << " " << *se.begin() <<endl;


    if (prefix>=1) ans += (af-prev)*(*se.begin());
    if (ad==1) {se.insert(as); }
    if (ad==-1) se.erase(se.find(as));

    prev = af;
    prefix+=ad;
  }
  cout << ans;
}
