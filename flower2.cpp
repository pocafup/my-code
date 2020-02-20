#include <iostream>
#include <algorithm>

using namespace std;

const int MIN = -1e8;
int dp[101][101];
int vis[101];
int a,b;
int nums[101][101];
int dfs(int pos, int num){
  int curr = 0;
  if (num==a-1) {curr = nums[pos][num];return curr;}
  for(int i=0;i<b;i++){
    if (vis[i]== false){
      vis[i] = true;
      if (dp[i][num+1]== MIN) dp[i][num+1] = dfs(i,num+1);
      curr = max(curr,dp[i][num+1]+nums[pos][num]);
      vis[i] = false;
    }
  }
  return curr;
}
int main(){
  cin >> a >> b;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      dp[i][j] = MIN;
    }
  }
  for (int i=0;i<a;i++)
    for (int j=0;j<b;j++)
      cin >> nums[i][j];
  for (int i=0;i<b;i++){
    vis[i] = true;
    dp[i][0] = dfs(i,0);
    vis[i] = false;
  }

  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}
