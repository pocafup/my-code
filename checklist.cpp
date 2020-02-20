#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>


using namespace std;

int main(){
  int a,b; cin >> a >> b;
  pair<int,int> G[a];
  pair<int,int> H[b];
  for (int i=0;i<a;i++) {cin >> G[i].first >> G[i].second;}
  for (int i=0;i<b;i++) {cin >> H[i].first >> H[i].second;}
  int dp[a][b][2];
  memset(dp,0,sizeof(dp));
  dp[0][0][1] = 10000;
  for (int i=1;i<a;i++){
    for (int j=1;j<b;j++){
      dp[i][j][0] = 10000;
      dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][0]+(G[i].first-G[i-1].first)*(G[i].first-G[i-1].first)
                      +(G[i].second-G[i-1].second)*(G[i].second-G[i-1].second));
      dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][1]+(pow((G[i].first-G[i-1].first),2)+pow((G[i].second-G[i-1].second),2)));
      dp[i][j][1] = 10000;
      dp[i][j][1] = min(dp[i][j][0],dp[i][j-1][1]+pow((H[i].first-H[i-1].first),2)+pow((H[i].second-H[i-1].second),2));
      dp[i][j][1] = min(dp[i][j][0],dp[i][j-1][0]+(pow((H[i].first-H[i-1].first),2)+pow((H[i].second-H[i-1].second),2)));
      cout << dp[i][j][0] << " " << dp[i][j][1] << endl;
    }
  }
}
