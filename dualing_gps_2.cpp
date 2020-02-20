#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
bool vis[100005];
vector<pp> adj1[100005],adj2[100005];
int n,m;
int dist1[100005],dist2[100005];
int dp[100005];
void spfa(int pos, int dist[], vector<pp> adj[100005]){
  dist[pos] = 0;
  queue<int> q;
  q.push(pos);
  while(!q.empty()){
    int qf = q.front();q.pop();
    vis[qf] = false;
    for (pp v : adj[qf]){
      if (dist[v.f]> dist[qf]+v.s){
        dist[v.f] = dist[qf]+v.s;
        if (!vis[v.f]) q.push(v.f);
      }
    }
  }
}
void spfa2(int pos){
  memset(dp,0x3f3f,sizeof(dp));
  dp[pos] = 0;
  queue<int> q;
  q.push(pos);
  while(!q.empty()){
    int qf = q.front();q.pop();
    // cout << qf << " " << dp[qf] << endl;
    for (int v=0;v<adj1[qf].size();v++){
      int to = adj1[qf][v].f;
      // cout << "d1 " << dist1[qf] << " " << dist1[to] << endl;
      int d1 = (dist1[qf]-adj1[qf][v].s==dist1[to]) ? 0 : 1;
      int d2 = (dist2[qf]-adj2[qf][v].s==dist2[to]) ? 0 : 1;
      if (dp[to]>dp[qf]+d1+d2){
        dp[to] = dp[qf]+d1+d2;
        if (!vis[to]){vis[to] = true;q.push(to);}
      }
    }
  }
}
void swop(vector<pp> adj[100005]){
  vector<pp> tmp[100005];
  for (int i=1;i<=n;i++){
    for (pp v : adj[i]){
      tmp[v.f].push_back(make_pair(i,v.s));
    }
  }
  for (int i=1;i<=n;i++) swap(tmp[i],adj[i]);
}
int main(){
  cin >> n >> m;
  for (int i=0;i<m;i++){
    int a,b,c,d; cin >> a >> b >> c >> d;
    adj1[b].push_back(make_pair(a,d));
    adj2[b].push_back(make_pair(a,c));
  }
  memset(dist1,0x3f3f,sizeof(dist1));
  memset(dist2,0x3f3f,sizeof(dist2));
  spfa(n,dist1,adj1);
  spfa(n,dist2,adj2);
  swop(adj1);
  swop(adj2);
  spfa2(1);
  cout << dp[n];
}
