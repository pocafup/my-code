#include <iostream>
#include <algorithm>

using namespace std;
#define INF 2000000000;
int dp[249][249];
int main(){
  int a;cin >> a;
  for (int i=0;i<a;i++) cin >> dp[i][i];
  // for (int j=0;j<=a;j++){
  //   for (int i=0;i<=a;i++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (i!=j){
        dp[i][j] = -INF;
      }
    }
  }
  for (int i=1;i<a;i++){
    for (int left=0;left<a-i;left++){
      int right = left+i;
      for (int cut=left;cut<right;cut++){
        if (dp[left][cut] == dp[cut+1][right])
          dp[left][right] = max(dp[left][right],dp[left][cut]+1);
      }
    }
  }
  int maxi = 0;
  for (int j=0;j<a;j++){
    for (int i=0;i<a;i++){
      cout << dp[i][j] << " ";
      maxi = max(maxi,dp[i][j]);
    }
    cout << endl;
  }
  cout << maxi;
}
