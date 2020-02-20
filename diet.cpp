#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int dp[45001][2];
int main(){
  int a,b;
  cin >> a >> b;
  int c[b];
  memset(dp,0,sizeof(dp));

  for (int i=0;i<b;i++){
    cin >> c[i];
  }
  int ans = 0;
  for(int i=0;i<b;i++){
    for (int j=0;j<=a;j++){
      if (j-c[i]>=0){
        dp[j][1] = max(dp[j-1][1],dp[j-c[i]][1]+c[i]);

      }else{
        if (j>=1) dp[j][1] = max(dp[j-1][1],dp[j][0]);
        dp[j][1] = max(dp[j][0],dp[j][1]);
      }
      if (dp[j][1]<=a){
        ans = max(max(ans,dp[j][1]),dp[j][0]);

      }
      ans = max(ans,dp[j][0]);
    }
    for (int k=0;k<a+1;k++){
      dp[k][0] = dp[k][1];
    }
    for (int j=0;i<b;i++){
        cout << dp[j][0] << " " <<dp[j][1] <<endl;
    }
  }

  cout << ans;
}
