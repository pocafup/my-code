#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  pair<int,int> c[a];
  for (int i=0;i<a;i++) cin >> c[i].first >> c[i].second;
  int dp[a+1][b+1];
  memset(dp,0,sizeof(dp));
  for (int i=0;i<=b;i++){
    dp[0][i] = 10000;
  }
  for (int i=1;i<=a;i++){
    for (int j=1;j<=b;j++){
      if (j<=c[i-1].first){
        dp[i][j] = min(dp[i-1][j],c[i-1].second);
      }else{
        dp[i][j] = min(dp[i-1][j],dp[i][j-c[i-1].first]+c[i-1].second);
      //  cout << dp[i-1][j] << " " << dp[i][j-c[i-1].first]+c[i-1].second << endl;
      }
    }
  }
  for (int i=0;i<a+1;i++){
    for (int j=0;j<b+1;j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
    cout << endl;
  }
  cout << dp[a][b];
}
