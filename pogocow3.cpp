#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> pos[1001];
pair<int,int> dp[1001][1001][2];
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++){
    cin >> pos[i].first >> pos[i].second;
  }
  sort(pos,pos+a);
  dp[0][0][0] = make_pair(pos[0].second,0);
  for (int i=1;i<a;i++){
    dp[i][0][1] = make_pair(pos[i].second,0);
    for (int j=1;j<=i;j++){
      for (int k=1;k<=j;k++){
        int dis = pos[i].first-min(pos[i-k].second,dp[i-j][j-k][0].second);
        if (dis >= dp[i-j][j-k][0].second){
          dp[i][j][1] = make_pair(dp[i-1][j-k][0].first+pos[i].second,dis);
        }
      }
    }
    for (int k=0;k<a;k++){
      dp[i][k][0] = dp[i][k][1];
    }
  }
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<a;j++){
  //     cout << dp[i][j][0].first <<  " " << dp[i][j][0].second << "  ";
  //   }
  //   cout << endl;
  // }
  int maxi = 0;

  for (int i=0;i<a;i++){
    maxi = max(maxi,dp[a-1][i][0].first);
  }
}
