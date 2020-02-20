#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
int n,m,k;
string s;
int pos[30][30];
int dist[30][30];
bool vis[30][30];
int pref[100001][30];
int dp[100001][30];
int dp2[100001];
void prefix(){
  for (int i=0;i<n-k;i++){
    for (int j=0;j<m;j++){
      for (int kk=i;kk<i+k;kk++){
        pref[i][j]+=dist[(int)(s[kk]-'a')][j];
      }
    }
  }
}
void floyd(){
  for (int kk=0;kk<m;kk++){
    for (int i=0;i<m;i++){
      for (int j=0;j<m;j++){
        dist[i][j] = min(dist[i][j],dist[i][kk]+dist[kk][j]);
      }
    }
  }
}

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

int main(){
  setIO("cowmbat");
  cin >> n >> m >> k >> s;
  for (int i=0;i<m;i++)
    for (int j=0;j<m;j++)
      cin >> dist[i][j];
  memset(dp,0x3f3f,sizeof(dp));
  for(int i=1;i<=n;i++){
    for (int j=0;j<m;j++){
       pref[i][j] = pref[i-1][j]+dist[s[i-1]-'a'][j];
    }
  }
  floyd();
  memset(dp2,0x3f3f,sizeof(dp2));
  dp2[0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<m;j++){
      dp[i][j] = min(dp[i][j], dp[i-1][j]+dist[s[i-1]-'a'][j]);
      if (i>=k) dp[i][j] = min(dp[i][j], pref[i][j]-pref[i-k][j]+dp2[i-k]);
      dp2[i] = min(dp2[i], dp[i][j]);
    }
  }
  cout << dp2[n];
}
