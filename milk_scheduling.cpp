#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,pos[100005],sz[100005],st[10005],update = 0,ans = 0;
bool vis[10005];
vector<int> adj[10005];
int main(){
  cin >> n >> m;
  for (int i=1;i<=n;i++) cin >> pos[i];
  for (int i=0;i<m;i++){
    int a,b; cin >> a >> b;
    adj[a].push_back(b);
    sz[b]++;
  }
  while(true){
    for (int i=1;i<=n;i++){
      if (vis[i]) continue;
      if (sz[i]==0){
        vis[i] = true;
        update++;
        ans = max(ans,st[i]+pos[i]);
        for (int v : adj[i]){
          sz[v]--;
          st[v] = max(st[v],st[i]+pos[i]);
        }
      }
    }
    if (update==n) break;
  }
  cout << ans;
}
