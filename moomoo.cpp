/*
ID:dx424391
PROG: mooomoo
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int dp[100000];
int product[100000];
int pos[100000];
int cost[100000];
#define INF 200000000;
int main(){
  ofstream cout("mooomoo.out");
  ifstream cin ("mooomoo.in");
  int a,b; cin >> a >> b;

  int maxi = 0;
  for (int i=1;i<=b;i++) cin >> cost[i];
  for (int i=0;i<a;i++) {
    cin >> pos[i];
    maxi = max(maxi,pos[i]);
  }
  int poo = 0;
  while(pos[poo] == 0) poo++;
  product[poo] = pos[poo];
  for (int i=poo+1;i<a;i++){
    if (pos[i-1]-pos[i]!=1){
      product[i] = pos[i]-pos[i-1]+1;
    }
  }

  for (int j=0;j<=99999;j++) dp[j] = INF;
  dp[0] = 0;

  for (int i=1;i<=b;i++){
    for (int j=0;j<=99999;j++){
      if (j-cost[i]>=0){
        dp[j] = min(dp[j],dp[j-cost[i]]+1);
      }
    }
  }
  int ans = 0;

  for (int i=0;i<a;i++){
    if(product[i]!=0){
      ans += dp[product[i]];
    }
  }
  cout << ans;
}




// for (int i=1;i<=b;i++){
//   for (int j=0;j<=maxi;j++){
//     dp[i][j] = INF;
//     if (dp[i-1][j]!=0 && j>pos[i]){
//       dp[i][j] = min(dp[i-1][j],dp[i-1][j-pos[i]]+1);
//     }else if (j>pos[i]){
//       dp[i][j] = 0;
//     }
//     dp[i][j] = min(dp[i][j],dp[i-1][j-pos[i]]+1);
//   }
// }
// for (int i=1;i<=b;i++){
//   for (int j=0;j<=maxi;j++){
//     (dp[i][j] != 2000) ? cout << dp[i][j] << " " : cout << "A" << " ";
//   }
//   cout << endl;
// }
