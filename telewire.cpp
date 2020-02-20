#include <iostream>
#include <algorithm>

using namespace std;
int pos[100001];
const int inf = 2*1e9;
int dp[100];
int maxi = 0;
int main(){
  int a,b; cin >> a >> b;
  for(int i=0;i<a;i++) {cin >> pos[i];maxi = max(maxi,pos[i]);}
  // cout << maxi << endl;
  for(int i=pos[0];i<=maxi;i++){
    dp[i] = (i-pos[0])*(i-pos[0]);
  }
  // for (int i=0;i<=maxi;i++) cout << dp[i] << " ";
  // cout << endl;
  for (int i=1;i<a;i++){
    int current[100];
    for (int k=0;k<100;k++) current[k] = inf;
    for (int j=pos[i-1];j<=maxi;j++){
      // cout << j << " " << maxi << endl;
      for (int k=pos[i];k<=maxi;k++){
        current[k] = min(current[k],dp[j]+(k-pos[i])*(k-pos[i])+b*abs(j-k));
        // cout << "      " << dp[j] << " " << (k-pos[i])*(k-pos[i]) << " " << b*abs(j-k) << endl;
      }
    }
    for (int j=0;j<=maxi;j++){
      dp[j] = current[j];
    }
    // for (int i=0;i<=a;i++){
    //   cout << dp[i] << " ";
    // }
    // cout << endl;
  }
  int ans = 1e9;
  for (int i=0;i<=maxi;i++) ans = min(ans,dp[i]);
  cout << ans;
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<=5;j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}
