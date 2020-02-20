#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[101][101];
int grid[101][101];
int main(){
  int a,b;cin >> a >> b;
  for (int i=0;i<a;i++)
    for (int j=0;j<b;j++)
      cin >> grid[i][j];
  memset(dp,-0x3f3f,sizeof(dp));
  for (int i=0;i<b;i++){
    dp[0][i] = grid[0][i];
  }
  for (int i=1;i<a;i++){
    for (int j=0;j<b;j++){
      for (int k=j+1;k<b;k++){
        dp[i][k] = max(dp[i][k],dp[i-1][j]+grid[i][k]);
        //cout << dp[i][k] << endl;
      }
    }
  }
  int maxi = 0;
  for (int i=0;i<b;i++){
    maxi = max(dp[a-1][i],maxi);
  }
  cout << maxi;
}
