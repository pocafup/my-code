#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int c[b];
  for (int i=0;i<b;i++){
    cin >> c[i];
  }
  int dp[a+1][2];

  memset(dp,0,sizeof(dp));
  for (int i=0;i<b;i++){
    for (int j=0;j<=a;j++){
      if (j-c[i]>=0){
        dp[j][1] = max(dp[j-1][1],dp[j-c[i]][0]+c[i]);
      }else{
        dp[j][1] = max(dp[j-1][1],dp[j][0]);
      }
      for (int k=0;k<=a;k++){
        cout <<  dp[k][0] << " ";
      }
      for (int k=0;k<=a;k++){
        dp[j][0] = dp[j][1];
      }
    }

  }

}
