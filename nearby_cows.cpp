#include <iostream>
#include <algorithm>

using namespace std;
#define BD 14
int n,k;
int val[100005],val2[100005],level[100005],ans[100005][30];
struct Edge{
  int from,to,next;
}edge[200005];
int tot = 0,head[100005];
void add(int f, int t){
  edge[++tot].from = f;
  edge[tot].to = t;
  edge[tot].next = head[f];
  head[f] = tot;
}

// void dfs(int pos, int value, int prev, int times){
//   val2[pos]+=value;
//   // cout << times << endl;
//   if (times==k) return;
//   for (int i=head[pos];i;i=edge[i].next){
//     if (edge[i].to!=prev) dfs(edge[i].to,value,pos,times+1);
//   }
// }
int LCA(int u, int v) {
	if(level[u] < level[v]) swap(u,v);

	int diff = level[u] - level[v];
	for(rei i=0; i<BD; i++) if((diff>>i)&1 ) u = ans[u][i];
	if(u == v) return u;
	for(rei i=BD-1; i>=0; i--) if(ans[u][i] != ans[v][i]) {
		u = ans[u][i];
		v = ans[v][i];
	}
	return ans[u][0];
}
void set_up_lca(int nn){
  for(rei i = 1 ; i <= BD ; i++){
    for(rei j = 0; j < nn ; j++){
      if(ans[j][i-1] != -1) ans[j][i] = ans[ans[j][i-1]][i-1] ;
    }
  }
}
void dfs(int pos, int lev, int prev){
  ans[pos][0] = prev;
  level[pos] = lev;
  for (rei i=head[pos];i;i=edge[i].next){
    int t = edge[i].to;

    if (t==prev) continue;
    dfs(t,lev+1,pos);
  }
}
int main(){
  cin >> n >> k;
  for (int i=0;i<n-1;i++){
    int a,b; cin >> a >> b;
    add(a,b); add(b,a);
  }
  dfs(1,0,-1);
  set_up_lca();
  for (int i=1;i<=n;i++) cin >> val[i];
  for (int i=1;i<=n;i++) {
    dfs(i,val[i],-1,0);
  }
  for (int i=1;i<=n;i++) cout << val2[i] << endl;
}
