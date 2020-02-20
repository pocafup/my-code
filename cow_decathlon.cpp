#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<pair<int,int> > bonus[21];
int pos[21][21];
int dp[1<<20];
int prefix[(1<<20)+1];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++){
    int c,d,e;cin >> c >> d >> e;
    bonus[c].push_back(make_pair(d,e));
  }
  for (int i=0;i<a;i++)
    for (int j=0;j<a;j++)
      cin >> pos[i][j];

  for (int i=1;i<(1<<a);i++){
    int go = i,count = 1;
    while(go>0) go/=2;count++;
    prefix[i] = count;
  }
  // for (int i=0;i<(1<<a);i++) cout << prefix[i] << " ";
  // cout << endl;
  int ans = 0;
  for (int i=1;i<(1<<a);i++){

      for (int j=0;(1<<j)<(1<<a);j++){
        for (int l=0;l<prefix[i]+j;l++){
        int cc = i%(1<<(j+1));
        if (cc<(1<<j)){
          int temp = 0;
          for (int k=0;k<bonus[j].size();k++){
            if (dp[i]+pos[j][l]>=bonus[j][k].first) temp = max(temp,bonus[j][k].second);
          }
          dp[i+(1<<j)] = max(dp[i+(1<<j)],dp[i]+pos[j][l]+temp);
          ans = max(dp[i+(1<<j)],ans);
        }
      }
    }

  }
  for (int i=0;i<(1<<a);i++) cout << dp[i] << " ";
  cout << endl;
  cout << ans;
}
