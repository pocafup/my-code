#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define ri register int
#define pp pair<int,int>
int dist1[50005];
int dist2[50005];
int du1[50005];
int du2[50005];
vector<pp> vec1[50005], vec2[50005], trav1[50005],trav2[50005];
int tot = 0, ans = 0, edg = 0;
int a,b;
void bfs(){
  queue<int> q;
  q.push(1);
  for (int i=1;i<=a;i++)du1[i] = 1e8;
  for (int i=1;i<=a;i++)du2[i] = 1e8;
  du1[1] = 0; du2[1] = 0;
  while(!q.empty()){
    int qf = q.front();
    q.pop();

    for (int i=0;i<trav1[qf].size();i++){
      int re1 = dist1[trav1[qf][i].first]!=dist1[qf]-trav1[qf][i].second;
      int re2 = dist2[trav2[qf][i].first]!=dist2[qf]-trav2[qf][i].second;
      if (du1[trav1[qf][i].first]>du1[qf]+re1 || du2[trav2[qf][i].first]>du2[qf]+re2){
        du1[trav1[qf][i].first] = min(du1[trav1[qf][i].first],du1[qf]+re1);
        du2[trav2[qf][i].first] = min(du2[trav2[qf][i].first],du2[qf]+re2);
        q.push(trav1[qf][i].first);
      }
    }
  }
}
bool vis[50005];
int dfs(int pos,int re){
  // cout << "e" << endl;
  int curr = 1e8;
  vis[pos] = true;
  if (pos==a) return re+du1[a]+du2[a];
  for (int i=0;i<trav1[pos].size();i++){
    if (vis[trav1[pos][i].first]) continue;
    vis[trav1[pos][i].first] = true;
    curr = min(curr,dfs(trav1[pos][i].first,re+du1[trav1[pos][i].first]+du2[trav1[pos][i].first]));
    vis[trav1[pos][i].first] = false;
    // if (pos==1) cout << curr << endl;
  }
  return curr;
}
void dijkstra(int dist[], vector<pp> vec[]){
  // memset(dist,0x3f3f,sizeof(dist));
  for (int i=1;i<=a;i++) dist[i] = 1e8;
  dist[a] = 0;
  // cout << a << endl;
  queue<int> q;
  q.push(a);
  while(!q.empty()){
    int qf = q.front();q.pop();
    // cout << qf <<" " << vec[qf].size() << endl;
    for (int i=0;i<vec[qf].size();i++){
      // cout << vec[qf][i].first << " " << vec[qf][i].second << endl;
      if (dist[vec[qf][i].first]>dist[qf]+vec[qf][i].second){
        dist[vec[qf][i].first]=dist[qf]+vec[qf][i].second;
        q.push(vec[qf][i].first);
      }
    }
  }
  // for (int i=1;i<=a;i++) cout << dist[i] << " " ;
  // cout << endl;
}
int main(){
  cin >> a >> b;
  for (int i=1;i<=b;i++){
    int c,d,e,f; cin >> c >> d >> e >> f;
    vec1[d].push_back(make_pair(c,e));
    vec2[d].push_back(make_pair(c,f));
    trav1[c].push_back(make_pair(d,e));
    trav2[c].push_back(make_pair(d,f));
  }
  dijkstra(dist1,vec1);
  dijkstra(dist2,vec2);
  // for (int i=1;i<=a;i++) cout << dist1[i] << " " ;
  // cout << endl;
  // for (int i=1;i<=a;i++) cout << dist2[i] << " " ;
  // cout << endl;

  bfs();
  // for (int i=1;i<=a;i++) cout << du1[i] << " ";
  // cout << endl;
  // for (int i=1;i<=a;i++) cout << du2[i] << " ";
  // cout << endl;
  cout << dfs(1,0);
  // cout << du1[a]+du2[a];
}
