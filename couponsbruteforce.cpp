#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


pair<long long,long long> cost[50001];
long long dp[2][50001];
bool sorted(pair<long long,long long> aa, pair<long long,long long> bb){
  return aa.first<bb.first;
}
int main(){
  long long a,b,c; cin >> a >> b >> c;
  for (long long i=1;i<=a;i++) {
    cin >> cost[i].first >> cost[i].second;
  }
  memset(dp,0x3f3f3f,sizeof(dp));
  dp[0][0] = 0;
  int up_to = 1;
  int ans = 0;
  sort(cost,cost+a,sorted);
  for (int i=1;i<=a;i++){
    dp[1][0] = dp[0][0]+cost[i].first;
    for (int j=1;j<=up_to;j++){
      dp[1][j] = min(dp[0][j]+cost[i].first,dp[0][j-1]+cost[i].second);
      if (dp[1][j]<=c) ans = max(ans,i);
    }
    for (int j=0;j<=up_to;j++) dp[0][j] = dp[1][j];
    up_to++;
    // for (int i=0;i<a;i++) cout <<dp[0][i] << " ";
    // cout << endl;
    // for (int i=0;i<a;i++) cout << dp[1][i] << " ";
    // cout <<endl;
  }
  // for (int i=0;i<=a;i++) cout <<dp[0][i] << " ";
  // cout << endl;
  // for (int i=0;i<=a;i++) cout << dp[1][i] << " ";
  // cout <<endl;
  cout << ans;
}
