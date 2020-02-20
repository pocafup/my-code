#include <iostream>
#include <algorithm>

using namespace std;

int graph[400][400];
int dp[1000000];
int main(){
  int a; cin >> a;
  int b[a];
  for (int i=0;i<a;i++) cin >> b[i];
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cin >> graph[i][j];
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout <<graph[i][j] << " ";
    }
    cout << endl;
  }
  for (int i=0;i<100000;i++){
    dp[i] = -1;
  }
  int dummy = 0;
  dp[dummy] = 0;
  for (int i=0;i<a;i++){
    if (graph[0][i] <= b[i]){
      dp[b[i]] = max(dp[b[i]],dp[0]+1);
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (b[i]+graph[i][j]<=b[j]){
        dp[b[j]] = max(dp[b[j]],dp[b[i]]+1);
      }
    }
  }
  int maxi = 0;
  for (int i=0;i<100000;i++){
    maxi = max(maxi,dp[i]);
  }
  cout << maxi;
}
