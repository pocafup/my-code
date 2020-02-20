#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  int a; cin >> a;
  int dp[a*a+1][a+1];
  memset(dp,0,sizeof(dp));
  dp[0][0] = 1;
  for (int i=1;i<=a;i++){
    for (int j=0;j<a*a;j++){
      if (j>=i){
        dp[j][i] = dp[j][i-1]+dp[j-i][i-1];
      }else{
        dp[j][i] = dp[j][i-1];
      }
    }
  }
  // for (int i=1;i<=a;i++){
  //   for (int j=0;j<a*a;j++){
  //     cout << dp[j][i] << " ";
  //   }
  //   cout << endl;
  // }
  int count = a*(a+1)/2;
//  cout << count;
  if (count % 2 != 1){
    cout << dp[count/2][a];
  }else{
    cout << 0;
  }
}
