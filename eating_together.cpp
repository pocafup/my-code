#include <iostream>
#include <algorithm>

using namespace std;
int n;
int dp[30005][4];
int dp2[30005][4];
int pos[30005];
int main(){
  cin >> n;
  for (int i=1;i<=n;i++) cin >> pos[i];
  // dp[0][1] = pos[0]<1; dp[0][2] = pos[0]<2; dp[0][3] = pos[0]<3;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=3;j++){
      if (j==1) dp[i][j] = dp[i-1][j]+(j!=pos[i]);
      if (j==2) dp[i][j] = min(dp[i-1][j]+(j!=pos[i]),dp[i-1][j-1]+(j-1!=pos[i]));
      if (j==3) dp[i][j] = min(min(dp[i-1][j]+(j!=pos[i]),dp[i-1][j-1]+(j-1!=pos[i])),dp[i-1][j-2]+(j-2!=pos[i]));
    }
  }
  for (int i=1;i<=n;i++){
    for (int j=1;j<=3;j++){
      if (j==3) dp2[i][j] = dp2[i-1][j]+(j!=pos[i]);
      if (j==2) dp2[i][j] = min(dp2[i-1][j]+(j!=pos[i]),dp2[i-1][j+1]+(j+1!=pos[i]));
      if (j==1) dp2[i][j] = min(min(dp2[i-1][j]+(j!=pos[i]),dp2[i-1][j+1]+(j+1!=pos[i])),dp2[i-1][j+2]+(j+2!=pos[i]));
    }
  }
  cout << min(min(min(dp2[n][1],dp2[n][2]),dp2[n][3]),min(min(dp[n][1],dp[n][2]),dp[n][3]));
}
