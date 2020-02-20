#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
int n,m;
vector<pp> adj[25];
int digit(int num){
  int re = 0;
  for (int i=n-1;i>=0;i--) if ((num>>i)&1) re++;
  return re;
}
int cow[25][25];
int dp[1<<21];
int main(){
  cin >> n >> m;
  for (int i=0;i<m;i++){
    int a,b,c; cin >> a >> b >> c;
    adj[a].push_back(make_pair(b,c));
  }
  for (int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      cin >> cow[i][j];
    }
  }
  // for (int i=0;i<n;i++) dp[(1<<i)] = cow[i+1][1];
  for (int i=1;i<(1<<n);i++){
    int k = digit(i);
    for (int j=0;j<n;j++){
      if ((i>>j)&1){
        int tmp = dp[i-(1<<j)]+cow[j+1][k];
        for (pp v : adj[k]){
          if (tmp>=v.f) tmp+=v.s;
        }
        dp[i] = max(dp[i],tmp);
      }
    }
  }
  cout << dp[(1<<n)-1];
}
