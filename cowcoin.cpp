#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
long long a,b;
pair<long long,long long> c[5002];
long long dp[5000][1000];

int ans(){
  memset(dp,0,sizeof(dp));
  long long ansv;

  for (long long j=1;j<=a;j++){
    for (long long i=0;i<=b;i++){
      if (i-c[j].first>=0){
        dp[i][j] = max(dp[i][j-1],dp[i-c[j].first][j-1]+c[j].second);
      }else{
        dp[i][j] = dp[i][j-1];
      }
      ansv = max(ansv,dp[i][j]);

    }
  }
  return ansv;
}
int main(){

  cin >> a >> b;
  memset(c,0,sizeof(c));
  for (long long i=1;i<=a;i++){
    cin >> c[i].first >> c[i].second;

  }

  sort(c,c+a+1);
  cout << ans();
  // for (long long j=0;j<=a;j++){
  //   for (long long i=0;i<=b;i++){
  //     cout << dp[j][i] << " ";
  //   }
  //   cout << endl;
  // }
}
