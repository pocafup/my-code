#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
int n,k;
pp pos[505];
int dp[505][505];
int dist(pp a, pp b){
  return abs(a.f-b.f)+abs(a.s-b.s);
}
int main(){
  cin >> n >> k;
  for (int i=1;i<=n;i++) cin >> pos[i].f >> pos[i].s;
  memset(dp,0x3f3f,sizeof(dp));
  dp[1][0] = 0;
  for (int i=2;i<=n;i++){
    for (int j=0;j<=k;j++){
      // if (i>j) dp[i][j] = dp[i-j][0]+dist(pos[i],pos[i-j]);
      dp[i][j] = min(dp[i][j],dp[i-1][j]+dist(pos[i],pos[i-1]));
      for (int kk=0;kk<=j;kk++){
        cout << "i= " << i << " j= " <<j << " "<< kk << " " << i-kk << "         " << j-kk << endl;
        if (i-kk-2) dp[i][j] = min(dp[i][j],dp[i-kk-2][j-kk]+dist(pos[i],pos[i-kk]));
      }
    }
  }
  for (int i=1;i<=n;i++){
    for (int j=0;j<=k;j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << dp[n][k];
}
