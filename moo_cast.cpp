#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <cstring>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
int n;
int rad[205],ans = 0;
pp pos[205];
bool vis[205];
vector<int> adj[205];
int dis(pp x, pp y){
  return (x.f-y.f)*(x.f-y.f)+(x.s-y.s)*(x.s-y.s);
}
int dfs(int pos){
  int sz = 1;
  vis[pos] = true;
  for (int v : adj[pos]){
    if (!vis[v]) sz+=dfs(v);
  }
  return sz;
}
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

int main(){
  // setIO("moocast");
  cin >> n;
  for (int i=1;i<=n;i++){
    cin >> pos[i].f >> pos[i].s >> rad[i];
  }
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      if (i!=j){
        if (dis(pos[i],pos[j])<=rad[i]*rad[i]){
          adj[i].push_back(j);
        }
      }
    }
  }
  for (int i=1;i<=n;i++) {memset(vis,0,sizeof(vis));ans = max(ans,dfs(i));}
  cout << ans;
}
