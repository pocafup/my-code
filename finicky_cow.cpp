#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define INF 200000000;
int dp[100000][2];
int main(){
  int a,b; cin >> a >> b;
  int num[a];
  for (int i=0;i<a;i++) cin >> num[i];
  for (int i=0;i<=b;i++){
    dp[i][0] = INF;
    dp[i][1] = INF;
  }
  int dis = b / (a-1);
  dp[0][0] = num[0];
  dp[0][1] = num[0];
  int begin = dis;
  cout << dis << endl;
  int zz,cc;
  for (int i=1;i<a;i++){
    for (int j=0;j<=b;j++){
      if (i%2 == 0) zz = 0; else zz = 1;
      if (zz == 0) cc = 1; else cc = 0;
      if (j-dis>=0){
        dp[j][zz] = min(dp[j][zz],dp[j-dis][cc]+abs(num[i]-j));
      }
      if (j-dis-1>=0){
        dp[j][zz] = min(dp[j][zz],dp[j-dis-1][cc]+abs(num[i]-j));
      }

    }
    for (int j=0;j<2;j++){
      for (int k=0;k<=b;k++){
        cout << dp[k][j] << " ";
      }
      cout << endl;
    }
    cout << num[i] << endl << endl;
  }
  for (int j=0;j<2;j++){
    for (int i=0;i<=b;i++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  (dp[b][0]<dp[b][1]) ? cout << dp[b][0] : cout << dp[b][1];

}
