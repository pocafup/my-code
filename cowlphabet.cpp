#include <iostream>
#include <algorithm>

using namespace std;
const int MOD = 97654321;
int n,p,l;
int dp[255][255][2];
int main(){
  cin >> n >> p >> l;
  memset(dp,-1,sizeof(dp));
  dp[0][0][0] = 1;
  for (int i=1;i<=l;i++){
    string a; cin >> a;
    int x = 0,y = 0;
    // cout << (int)'Z' << " " << (int)'a' << endl;
    for (int j=0;j<a.length();j++) if ((int)a[j]<(int)'a') x++; else y++;
    // cout over x << " " <<  y << endl;
    for (int j=250;j>=0;j--){
      for (int k=250;k>=0;k--){
        if (dp[j][k][(i+1)%2]>0){
          cout << j << " " << k << " "  << i << endl;
          if (dp[j+x][k+y][(i+1)%2]>0){
            dp[j+x][k+y][i%2] = (dp[j+x][k+y][(i+1)%2]+dp[j][k][(i+1)%2])%MOD;
          }else{
            dp[j+x][k+y][i%2] = max(dp[j+x][k+y][i%2],dp[j][k][(i+1)%2]%MOD);
          }
        }
      }
    }
  }
  cout << dp[n][p][l%2]%MOD;
}
