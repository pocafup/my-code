#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;
#define pp pair<long long,long long>
long long dp[1001][1001][2];
pp hos[1001],gel[1001];
long long dist(pp a, pp b){
  return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
long long h,g;
int main(){
  // ifstream cin ("checklist.in");
  // ofstream cout ("checklist.out");
  cin >> h >> g;
  for (long long i=1;i<=h;i++) cin >> hos[i].first >> hos[i].second;
  for (long long i=1;i<=g;i++) cin >> gel[i].first >> gel[i].second;
  memset(dp,0x3f3f,sizeof(dp));
  dp[1][0][0] = 0;
  for (long long i=1;i<=h;i++){
    for (long long j=0;j<=g;j++){
      dp[i][j][0] = min(dp[i][j][0],min(dp[i-1][j][1]+dist(hos[i],gel[j]),dp[i-1][j][0]+dist(hos[i],hos[i-1])));
      if (j) dp[i][j][1] = min(dp[i][j][1],min(dp[i][j-1][1]+dist(gel[j],gel[j-1]),dp[i][j-1][0]+dist(gel[j],hos[i])));
    }
  }
  cout << dp[h][g][0];
}
