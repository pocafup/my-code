#include <iostream>
#include <algorithm>

using namespace std;

int dp[5000];
bool sorted(pair<int,int> aa, pair<int,int> bb){
  return aa.second<bb.second;
}
pair<int,int> pos[50000];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++) cin >> pos[i].first >> pos[i].second;
  sort(pos,pos+b,sorted);
  for (int i=0;i<=a;i++) dp[i] = 1;
  for (int i=b-1;i>=0;i--){
    dp[pos[i].first] = dp[pos[i].second]+1;
  }
  for (int i=0;i<=a;i++) cout << dp[i] << " ";
}
