#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> pp;
int dp_left[40001],dp_right[40001],lef[40001],ri[40001];
bool sorted(pp aa, pp bb){
  if (aa.first!=bb.first) return aa.first<bb.first;
  return aa.second<bb.second;
}
pp arr[100001];
int main(){
  int a,b,c; cin >> a >> b>> c;
  for (int i=0;i<a;i++) {cin >> lef[i]; dp_left[i] = lef[i];}
  for (int i=0;i<b;i++) {cin >> ri[i];dp_right[i] = ri[i];}
  for (int i=0;i<c;i++) {cin >> arr[i].first >> arr[i].second;arr[i].first--;arr[i].second--;}
  sort(arr,arr+c,sorted);
  int ans = 0;
  for (int i=0;i<c;i++){
    int af = arr[i].first;
    int as = arr[i].second;
    int prev1 = dp_left[af];
    dp_left[af] = max(dp_left[af],dp_right[as]+lef[af]);
    dp_right[as] = max(dp_right[as],prev1+ri[as]);
  }
  for (int i=0;i<a;i++) ans = max(dp_left[i],ans);
  for (int i=0;i<b;i++) ans = max(dp_right[i],ans);
  cout << ans;
}
