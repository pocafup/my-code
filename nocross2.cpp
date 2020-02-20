#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int fd1[1001],fd2[1001];
int dp[1001][1001];
int main(){
  ifstream cin ("nocross.in");
  ofstream cout ("nocross.out");
  int a,maxi = 0; cin >> a;
  for (int i=1;i<=a;i++) cin >> fd1[i];
  for (int i=1;i<=a;i++) cin >> fd2[i];

  for (int i=1;i<=a;i++){
    for (int j=1;j<=a;j++){
      int re = 0;
      if (abs(fd1[i]-fd2[j])<=4) re = 1;
      dp[i][j] = max(max(dp[i-1][j-1]+re,dp[i][j-1]),dp[i-1][j]);
      maxi = max(maxi,dp[i][j]);
    }
  }
  cout << maxi;
}
