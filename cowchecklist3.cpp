#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1e8*2;
long long dis(pair<long long,long long> aa, pair<long long,long long> bb){
  return (aa.first-bb.first)*(aa.first-bb.first)+(aa.second-bb.second)*(aa.second-bb.second);
}
pair<long long,long long> pos1[1005],pos2[1005];
long long dp[1005][1005][2];
long long a,b;
int main(){
  cin >> a >> b;
  for (long long i=0;i<a;i++) cin >> pos1[i].first >> pos1[i].second;
  for (long long i=0;i<b;i++) cin >> pos2[i].first >> pos2[i].second;
  for (long long i=0;i<=a;i++){
    for (long long j=0;j<=b;j++){
      dp[i][j][0] = INF;
      dp[i][j][1] = INF;
    }
  }
  dp[1][0][0] = 0;
  for (long long i=1;i<=a;i++){
    for (long long j=0;j<=b;j++){
      long long xpos = i-1;
      long long ypos = j-1;
      if (i==1&&j==0){
        continue;
      }else if(i==1){
        dp[i][j][1] = min(dp[i][j-1][0]+dis(pos1[xpos],pos2[ypos]),dp[i][j-1][1]+dis(pos2[ypos-1],pos2[ypos]));
      }else if (j==0){
        dp[i][j][0] = dp[i-1][j][0] + dis(pos1[xpos],pos1[xpos-1]);
      }else{
        dp[i][j][0] = min(dp[i-1][j][0]+dis(pos1[xpos],pos1[xpos-1]),dp[i-1][j][1]+dis(pos1[xpos],pos2[ypos]));
        dp[i][j][1] = min(dp[i][j-1][0]+dis(pos1[xpos],pos2[ypos]),dp[i][j-1][1]+dis(pos2[ypos-1],pos2[ypos]));
      }
    }
  }
  // for (long long i=0;i<=b;i++){
  //   for (long long j=0;j<=a;j++){
  //     cout << dp[j][i][0] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // for (long long i=0;i<=b;i++){
  //   for (long long j=0;j<=a;j++){
  //     cout << dp[j][i][1] << " ";
  //   }
  //   cout << endl;
  // }
  cout << dp[a][b][0];
}
