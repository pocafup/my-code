#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
int quan[10005],dfn[10005],low[10005],quan2[10005],head[10005];
bool vis[10005];
int dp[10005];
int pre = 0,curr = 0,ans = 0;
vector<int> adj[10005],arr[10005],tmp[10005],adj2[10005];
stack<int> st;
void tarjan(int pos){
  st.push(pos);
  vis[pos] = true;
  dfn[pos] = low[pos] = ++pre;
  for (int v : adj[pos]){
    if (!dfn[v]){
      tarjan(v);
      low[pos] = min(low[pos],low[v]);
    }else if (vis[v]) low[pos] = min(low[pos],dfn[v]);
  }
  if (dfn[pos]==low[pos]) {
    curr++;
    while(st.size()){
      int stt = st.top();
      head[stt] = curr;
      tmp[curr].push_back(stt);
      quan2[curr]+=quan[stt];
      st.pop();
      vis[stt] = false;
      if (stt==pos) break;
    }
  }
}
int main(){
  cin >> n >> m;
  for (int i=1;i<=n;i++) cin >> quan[i];
  for (int i=0;i<m;i++){
    int a,b; cin >> a >> b;
    adj[a].push_back(b);
  }
  for (int i=1;i<=n;i++){
    if (!dfn[i]) tarjan(i);
  }
  for (int i=1;i<=curr;i++){
    memset(vis,0,sizeof(vis));
    vis[i] = true;
    for (int u : tmp[i]){
      for (int v : adj[u]){
        if (!vis[head[v]]){
          vis[head[v]] = true;
          adj2[i].push_back(head[v]);
        }
      }
    }
  }
  for (int i=1;i<=curr;i++) ans = max(ans,dp[i]);
  cout << ans;
}
