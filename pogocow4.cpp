#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> pos[1001];
pair<int,int> dp[1001][1001];
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++){
    cin >> pos[i].first >> pos[i].second;
  }
  sort(pos,pos+a);
  dp[0][0] = make_pair(pos[0].second,0);
  for (int i=1;i<a;i++){
    dp[i][i] = make_pair(pos[i].second,0);
    for (int j=0;j<i;j++){
      for (int k=0;k<i;k++){
        int dis = dp[k][j].second;
        //cout << j << "    " << k << " " << dis << endl;
        if (pos[i].first-pos[k].first >= dis) {
          dp[i][j] = make_pair(dp[k][j].first+pos[i].second,pos[i].first-pos[k].first);
          //cout << pos[i].first << " " << pos[k].first << endl;
          for (int i=0;i<a;i++){
            // for (int j=0;j<a;j++){
            //   cout << dp[i][j].first << " " << dp[i][j].second << "   ";
            // }
            // cout << endl;
          }
        }
      }
    }
  }
  int maxi = 0;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      maxi = max(maxi,dp[i][j]);
    }
  }
  cout << maxi;
}
