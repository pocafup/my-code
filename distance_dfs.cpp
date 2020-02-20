#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
#define pp pair<int,int>
int level[200001];
int ans[200001][30],next,head[500005];
bool vis[200001];
struct Edge{
  int from,to,dis,next;
}edge[500005];

int tot = 0;
void add(int f,int t,int d){
  edge[++tot].from = f;
  edge[tot].to = t;
  edge[tot].dis = d;
  edge[tot].next = head[f];
  head[f] = tot;
}
int lca(int a,int b){
  if (level[a]<level[b]) swap(a,b);
  int dist = level[a]-level[b];
  for (int i=17;i>=0;i--) if (level[a]-(1<<i)>=level[b]) a = ans[a][i];
  if (a==b) return a;
  for (int k=17;k>=0;k--){
    if(ans[a][k] != -1 && ans[a][k]!=ans[b][k]){
      a = ans[a][k];
      b = ans[b][k];
    }
  }
  return ans[a][0];
}
void dfs(int pos, int lev){
  vis[pos] = true;
  level[pos] = lev;
  for (int i=head[pos];i;i=edge[i].next){
    int t = edge[i].to;
    if (!vis[t]) dfs(t,lev+1);
  }
}
void set_up_lca(int nn){
  for(int i = 1 ; i <= nn ; i++){
    for(int j = 1; (1<<j) < nn ; j++){
      if(ans[i][j-1] != -1) ans[i][j] = ans[ans[i][j-1]][j-1] ;
    }
  }
}
int seg[100005];
int main(){
  int a,b; cin >> a >> b;
  memset(ans,-1,sizeof(ans));
  for (int i=0;i<a-1;i++){
    int n1,n2;cin >> n1 >> n2;
    if (n2<n1) swap(n1,n2);
    add(n1,n2,1);
    ans[n2][0] = n1;
  }
  set_up_lca(a);
  dfs(1,0);
  for (int i=0;i<b;i++){
    int q1,q2; cin >> q1 >> q2;
    cout << level[q1]+level[q2]-2*level[lca(q1,q2)] << endl;
  }

}
