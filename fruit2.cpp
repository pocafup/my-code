#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  int a,b,c; cin >> a >> b >> c;
  bool dp[a+1][2];
  memset(dp,0,sizeof(dp));
  for (int i=1;i<=a;i++){
    if (i>=b && i%b == 0) dp[i][0] = 1;
    if (i>=c && i%c == 0) dp[i][0] = 1;
    if (i>=b) if (dp[i-b][0] == 1) dp[i][0] = 1;
    if (i>=c) if (dp[i-c][0] == 1) dp[i][0] = 1;

    if (dp[i][0] == 1) dp[i/2][1] = 1;
    if (i/2>=b) dp[i/2+b][1] = 1;
    if (i/2>=c) dp[i/2+c][1] = 1;
    if (i>=b) if (dp[i-b][1] == 1) dp[i][1] = 1;
    if (i>=c) if (dp[i-c][1] == 1) dp[i][1] = 1;

  }
  for (int i=0;i<=a;i++){
    dp[i][0] ? cout << i << " " : cout << 0 << " ";
  }
  cout << endl;
  for (int i=0;i<=a;i++){
    dp[i][1] ? cout << i << " " : cout << 0 << " ";
  }
  cout << endl;
  for (int i=a;i>=0;i--){
    if (dp[i][0] == 1 || dp[i][1] == 1){
      cout << i;
      break;
    }
  }
}
