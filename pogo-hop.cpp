#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> pos[1001];
pair<pair<int,int>,int> dp[1001][1001][2];
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >> pos[i].first >> pos[i].second;
  sort(pos,pos+a);
  dp[0][0][0] = make_pair(make_pair(pos[0].second,0),pos[0].first);
  for (int i=1;i<a;i++){
    dp[i][0][1] = make_pair(make_pair(pos[i].second,0),pos[i].second);
    for (int j=1;j<=i;j++){
      int dis = pos[i].first-pos[i-1].first;
      // cout << dis << " " << dp[i-1][j-1][0].second << endl;
      if (dis>=dp[i-1][j-1][0].first.second){
        // if (dp[i-1][j][0].first>dp[i-1][j-1][0].first+pos[i].second){
        //   dp[i][j][1] = dp[i-1][j][0];
        // }else{
        //   dp[i][j][1] = make_pair(dp[i-1][j-1][0].first+pos[i].second,dis)
        // }
        dp[i][j][1] = make_pair(make_pair(dp[i-1][j-1][0].first.first+pos[i].second,dis),pos[i].first);
      }else{
        for (int k=0;k<j;k++){
          if (dis>=pos[i].first-dp[i-1][k][0].second){
            dp[i][j][1] = make_pair(dp[i-1][k][0].first,dis);
          }
        }

      }
        //cout << i << " " << j << " " << dp[i][j][1].first << " " << dp[i-1][j-1][0].first<< endl;

    }
    for (int j=0;j<a;j++){
      dp[i][j][0] = dp[i][j][1];

    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout << dp[i][j][0].first.first << " ";
    }
    cout << endl;
  }
  cout << endl;
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<a;j++){
  //     cout << dp[i][j][1].first << " ";
  //
  //   }
  //   cout << endl;
  // }
  cout << endl;
}
