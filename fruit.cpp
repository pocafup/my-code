#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  int a,b,c; cin >> a >> b >> c;
  int dp[50001][2];
  int str[50001];
  memset(str,0,sizeof(str));
  memset(dp,0,sizeof(dp));
  for (int i=0;i<=a;i++){
    if(i>=b){
      dp[i][0] = dp[i-b][0]+b;
    }
    if (i>=c){
      dp[i][1] = dp[i-c][1]+c;
    }
  }

  int maxi = 0;

  for (int i=0;i<=a;i++){
    maxi = max(dp[i][0]/2+dp[a-dp[i][0]/2][1],maxi);
    maxi = max(dp[i][0]/2+dp[a-dp[i][0]/2][0],maxi);
    maxi = max(dp[i][1]/2+dp[a-dp[i][1]/2][0],maxi);
    maxi = max(dp[i][1]/2+dp[a-dp[i][1]/2][1],maxi);
  }
  maxi = max(b*(a/b),maxi);
  maxi = max(c*(a/c),maxi);
  cout << maxi;
}
