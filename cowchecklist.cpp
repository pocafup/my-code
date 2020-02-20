#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
#define INF 1e8*2;
int dis(pair<int,int> aa, pair<int,int> bb){
  return (aa.first-bb.first)*(aa.first-bb.first)+(aa.second-bb.second)*(aa.second-bb.second);
}
int a,b;
pair<int,int> pos1[1005];
pair<int,int> pos2[1005];
int dp[1005][1005][2];
int main(){
  cin >> a >> b;
  for (int i=0;i<a;i++) cin >> pos1[i].first >> pos2[i].second;
  for (int j=0;j<b;j++) cin >> pos2[j].first >> pos2[j].second;
  for (int i=0;i<a+1;i++){
    for (int j=0;j<b+1;j++){
      dp[i][j][0] = INF;
      dp[i][j][1] = INF;
    }
  }
  dp[1][0][0] = 0;
  dp[1][1][1] = dis(pos1[0],pos2[0]);
  for (int i=0;i<=a;i++){
    for (int j=0;j<=b;j++){
      cout << dp[i][j][1] << " ";
    }
    cout << endl;
  }
  for (int i=2;i<=a;i++){
    for (int j=0;j<=b;j++){

      if (j>=1) {
        dp[i][j][0] = min(min(dp[i][j][0],(dp[i-1][j][0]+dis(pos1[i-2],pos1[i-1]))),dp[i-1][j][1]+dis(pos2[j-1],pos1[i-1]));

        dp[i-1][j][1] = min(dp[i-1][j][1],min(dp[i-1][j-1][1]+dis(pos2[j-2],pos2[j]),dp[i-1][j-1][0]+dis(pos1[i-2],pos2[j])));
      }else{
        dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][0]+dis(pos1[i-2],pos1[i-1]));
      }
    }
  }
  for (int i=0;i<=a;i++){
    for (int j=0;j<=b;j++){
      cout << dp[i][j][0] << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (int i=0;i<=a;i++){
    for (int j=0;j<=b;j++){
      cout << dp[i][j][1] << " ";
    }
    cout << endl;
  }
}
