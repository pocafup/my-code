#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  string a,b; cin >> a >> b;
  int dp[a.size()+1][b.size()+1];
  memset(dp,10000,sizeof(dp));

  for (int i=0;i<=a.size();i++){
    dp[i][0] = i;
  }
  for (int i=0;i<=b.size();i++){
    dp[0][i] = i;
  }
  // for(int i=0;i<a.size()+1;i++){
  //   for (int j=0;j<b.size()+1;j++){
  //     cout << dp[i][j];
  //   }
  //   cout << endl;
  // }

  for (int i=1;i<=a.size();i++){
    for (int j=1;j<=b.size();j++){
      if (a[i-1] == b[j-1]){
        dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
      }else{
        dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
        dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
      }
      dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1);

    }
  }
  // for(int i=0;i<a.size()+1;i++){
  //   for (int j=0;j<b.size()+1;j++){
  //     cout << dp[i][j];
  //   }
  //   cout << endl;
  // }
  cout << dp[a.size()][b.size()];
}
