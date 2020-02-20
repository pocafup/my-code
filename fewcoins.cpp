#include <iostream>
#include <algorithm>

using namespace std;
#define INF 2*1e8;
int dp[1200000][2];
int N,T;
int pay[10001];
int cost[10001];

int main(){
  cin >> N >> T;
  for (int i=0;i<N;i++) cin >> pay[i];
  for (int i=0;i<N;i++) cin >> cost[i];
  for (int i=0;i<1200000;i++)
    for (int j=0;j<2;j++)
      dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i=0;i<N;i++){
    for (int j=1;j<120000;j++){
      if (j-pay[i]>=0){
        // cout << j << " " << pay[i] << endl;
        dp[j][1] = min(dp[j][1],min(dp[j-pay[i]][0]+1,dp[j-pay[i]][1]+1));
      }
    }
    for (int j=1;j<120000;j++) dp[j][0] = dp[j][1];
  }
  for (int j=0;j<=T;j++){
    if (dp[j][0]!=2*1e8) cout << dp[j][0] <<" " <<  j << endl;
  }
  cout << endl << endl;
  for (int i=0;i<N;i++){
    for (int j=0;j<120000;j++){
      dp[j][1] = min(dp[j][1],min(dp[j+cost[i]][0]+1,dp[j+cost[i]][1]+1));
    }
    for (int j=1;j<120000;j++) dp[j][0] = dp[j][1];

  }
  for (int j=0;j<=T;j++){
    if (dp[j][0]!=2*1e8) cout << dp[j][0] <<" " <<  j << endl;
  }

  cout << dp[T][0] ;
}
