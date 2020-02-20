#include <iostream>
#include <algorithm>

using namespace std;
long long a,b;
pair<long long,long long> c[5002];

int ans(){
  long long dp[b+2][a+2],ansv = 0;
  memset(dp,0,sizeof(dp));

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
  for (long long i=1;i<=a;i++){
    cin >> c[i].first >> c[i].second;
    cout << i << endl;
    if (i == 657){

      cout << c[i].first << c[i].second << "aa";
    }
  }
  sort(c,c+a+1);
  cout << ans();

}
