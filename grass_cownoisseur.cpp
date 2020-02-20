#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int dfn[200005],low[200005],head[200005],quan[200005],dist[200005],dist2[200005];
bool vis[200005];
int dp[200005];
int pre = 0,curr = 0,ans = 0;
queue<int> q;
vector<int> adj[200005],arr[200005],tmp[200005],adj2[200005],adj3[200005];
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
      quan[curr]++;
      st.pop();
      vis[stt] = false;
      if (stt==pos) break;
    }
  }
}

void spfa(int pos, int tmp[], vector<int> vec[200005]){
  memset(vis,0,sizeof(vis));
  tmp[pos] = quan[pos];
  q.push(pos);
  while(!q.empty()){
    int qf = q.front();q.pop();
    vis[qf] = false;
    for (int v : vec[qf]){
      // cout << v << endl;
      if (tmp[v]<tmp[qf]+quan[v]){
        tmp[v] = tmp[qf]+quan[v];
        if (!vis[v]){q.push(v);vis[v] = true;}
      }
    }
  }
}
int main(){
  cin >> n >> m;
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
          adj3[head[v]].push_back(i);
        }
      }
    }
  }

  spfa(head[1],dist,adj2);
  spfa(head[1],dist2,adj3);
  ans = quan[head[1]];
  for(int i=1;i<=curr;i++)
    if(dist[i]){

    for(int v : adj3[i]){
        if(!dist2[v])continue;
        ans=max(ans,dist[i]+dist2[v]-quan[head[1]]);
    }

  }
  cout << ans;
}
