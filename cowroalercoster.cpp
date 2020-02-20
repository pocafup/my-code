#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

pair<pair<int,int>,pair<int,int> > pos[10001];
int dp[1001][1001];
int a,b,c,d;

bool sorted(pair<pair<int,int>,pair<int,int> > aa,pair<pair<int,int>,pair<int,int> > bb){
  return aa.first.first<bb.first.first;
}
int main(){
  cin >> a >> b >> c;
  for (int i=0;i<=c;i++)
    for (int j=0;j<=c;j++)
      dp[i][j] = -1;

  dp[0][0] = 0;
  for (int i=0;i<b;i++){
    cin >> pos[i].first.first >> d >> pos[i].second.first >> pos[i].second.second;
    pos[i].first.second = pos[i].first.first+d;
  }
  sort(pos,pos+b,sorted);
  for (int i=0;i<b;i++){
    for (int j=0;j<c;j++){
      if(j+pos[i].second.second<=c && dp[pos[i].first.first][j]!=-1){
        dp[pos[i].first.second][j+pos[i].second.second] =
          max(dp[pos[i].first.second][j+pos[i].second.second],
              dp[pos[i].first.first][j]+pos[i].second.first);
      }
    }
  }
  int ans = 0;
  for (int i=0;i<=c;i++){
    ans = max(dp[a][i],ans);
  }
  for (int i=0;i<b;i++){
    for (int j=0;j<=c;j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << ans;
}
