#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  pair<int,int> corr[a];
  for (int i=0;i<a;i++){
    cin >> corr[i].first >> corr[i].second;
  }
  long long dp[a+1][b+1];
  memset(dp,0,sizeof(dp));
  for (int j=0;j<=b;j++){

    for (int i=1;i<a+1;i++){
      dp[i][j] = 100000000;
      if (i>=2 && j>0){
        int z = j,zz = 1+j;
        while(z>=0){
          dp[i][j] = min(dp[i][j],dp[i-zz][j-z]+abs(corr[i].first-corr[i-zz].first)+abs(corr[i].second-corr[i-zz].second));
          zz--;
          z--;

        }
      }else{
        dp[i][j] = min(dp[i][j],dp[i-1][j]+abs(corr[i].first-corr[i-1].first)+abs(corr[i].second-corr[i-1].second));
      }

    }
  }

  cout << dp[a-1][b];
}
