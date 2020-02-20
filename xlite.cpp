#include <iostream>
#include <algorithm>

using namespace std;
int dp[20001];
int main(){
  int a; cin >> a;
  for (int i=0;i<20000;i++) dp[i] = 200000;
  dp[1] = 1;
  dp[2] = 2;
  int turn = 2;
  while(dp[a]>1e5){
    for (int i=0;i<=a;i++) cout << dp[i] << " ";
    cout << endl;
    turn++;
    for (int i=a;i>=1;i--){
      if (dp[i]<1e5){
        for (int j=0;j<=i;j++){
          if(i+j<20001 && (dp[i]>dp[j]) ) dp[i+j] = min(dp[i+j],turn);
          else if (i+j<20001&&i==j) dp[i+j] = min(dp[i+j],turn);
          else if (i+j<20001 && i!=j) dp[i+j] = min(dp[i+j],turn+1);
        }
      }
    }
  }
  for (int i=0;i<=a;i++) cout << dp[i] << " ";

  cout << dp[a];
}
