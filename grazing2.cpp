#include <iostream>
#include <algorithm>

using namespace std;
#define INF 2000000000;
int dp[1500][1500];
int pos[1500];

int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> pos[i];
  sort(pos,pos+a);

  int d = (b-1)/(a-1);
  cout << d << endl;
  int p = (b-1)%(a-1);
  for (int i=0;i<=b;i++)
    for (int j=0;j<=p;j++)
      dp[i][j] = INF;
  dp[0][0] = pos[0]-1;
  for (int i=1;i<a;i++){
    for (int j=0;j<a;j++){
      if (i>0 && j>0) dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+abs(pos[i]-(d*i+j+1));
      else if (i>0) dp[i][j] = dp[i-1][j]+abs(pos[i]-(d*i+j+1));
    }
  }
  for (int j=0;j<a;j++){
    for (int i=0;i<a;i++){

      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << dp[a-1][p];
}
