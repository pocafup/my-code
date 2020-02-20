#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  pair<int,int> sta[a];
  for (int i=0;i<a;i++){
    cin >> sta[i].first >> sta[i].second;
  }
  int dp[b+1][2];
  memset(dp,0,sizeof(dp));
  for (int j=0;j<a;j++){
    for (int i=1;i<b+1;i++){
      if (i>=sta[j].first){
        dp[i][1] = max(dp[i][1],dp[i-sta[j].first][0]+sta[j].second);
      }else{
        dp[i][1] = max(dp[i][1],dp[i-1][1]);
      }
    }
    for (int i=1;i<b+1;i++){
      dp[i][0] = dp[i][1];
    }
  }
  cout << dp[b+1][1];
}
