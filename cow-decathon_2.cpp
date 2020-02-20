#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cow[21][21];
int dp[2][(1<<20)+1];
vector<pair<int,int> > bonus[21];
int a,b,c,d,e;
int main(){
  cin >> a >> b;

  for (int i=0;i<b;i++){
    cin >> c  >> d >> e;
    bonus[c].push_back(make_pair(d,e));
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cin >> cow[i][j];
    }
  }
  for (int i=0;i<a;i++){
    for (int j=1<<a;j>=0;j--){
      for (int k=0;k<a;k++){
        int cc = j%(1<<(k+1));
        if (cc>=(1<<k)){
          int current = dp[i%2][j-(1<<k)]+cow[k][i];
          int temp = 0;
          for (int l=0;l<bonus[k].size();l++){
            if (bonus[k][l].first<=current) temp = max(temp,bonus[k][l].second);
          }
          dp[(i+1)%2][j] = max(dp[(i+1)%2][j],current+temp);
        }
      }
    }
  }
  int ans = 0;
  // for (int i=0;i<(1<<a);i++) cout << dp[0][i] << " ";
  // cout << endl;
  // for (int i=0;i<(1<<a);i++) cout << dp[1][i] << " ";
  // cout << endl;
  for (int i=0;i<a;i++) ans = max(ans,dp[a%2][(1<<a)-1]);
  cout << ans;
}
