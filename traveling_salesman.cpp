#include <iostream>
#include <algorithm>

using namespace std;

int dp[20][1<<20];
int graph[21][21];
int n,m;

int travelling_salesman(int start1){
  memset(dp,-1,sizeof(dp));
  dp[0][start1] = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<(1<<n);j++){
      if (dp[(i+start1)%n][j]!=-1){
        for (int k=0;k<n;k++){
          if (graph[(i+start1)%n][k] && !((j>>k)&1)){
            int cur = dp[(i+start1)%n][j]+graph[(i+start1)%n][k];
            if (dp[k][j|(1<<k)] == -1 || dp[k][j|(1<<k)]>cur) dp[k][j|(1<<k)] = cur;
          }
        }
      }
    }
  }
  int ans = -1;
  for (int i=0;i<n;i++){
    cout << dp[(i+start1)%n][(1<<n)-1] << " " << graph[i][0] << endl;
    if (dp[(i+start1)%n][(1<<n)-1]!=-1 && graph[(i+start1)%n][0]){

      if (ans == -1 || dp[(i+start1)%n][(1<<n)-1]<ans){
        ans = dp[(i+start1)%n][(1<<n)-1];
      }
    }
  }
  return ans;
}

int main(){
  cin >> n >> m;
  for (int i=0;i<m;i++){
    int c,d,e; cin >> c >> d >> e;
    c--;d--;
    graph[c][d] = e;
    graph[d][c] = e;
  }
  int answ = -1;


    int cc = travelling_salesman(0);
    if (answ == -1|| cc!=-1){
      answ = min(answ,cc);
    }



  cout << answ;
}
