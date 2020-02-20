#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define pp pair<int,int>
pp pos[100001],temp[100001];
bool sorted (pp a, pp b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}
int main(){
  int n; cin >> n;
  for (int i=0;i<n;i++) {int aa; cin >> aa; pos[i] = make_pair(aa,i);}
  sort(pos,pos+n,sorted);
  int ans = 0;
  for (int i=0;i<n;i++) ans = max(ans,pos[i].second-i);
  cout << ans+1;
}
