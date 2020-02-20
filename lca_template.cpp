#include <iostream>
#include <cstdio>
inline long long read() {
      long long x=0,w=1;
      char ch;
      while(ch<'0'||ch>'9')
      {
          if(ch=='-')
              w=-1;
          ch=getchar();
     }
     while(ch>='0'&&ch<='9')
         x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
     return x*w;
 }
using namespace std;
#define BD 14
#define rei register int
int n,m,q,ans[1000005][30],head[1000005],level[1000005];
struct Edge{
  int from,to,next;
}edge[500005*6];
int tot = 0 ;
void add(int f,int t){
  edge[++tot].to = t;
  edge[tot].from = f;
  edge[tot].next = head[f];
  head[f] = tot;
}
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
  n = read();m = read();q = read();
  for (int i=0;i<n-1;i++){
    int a,b; a = read();b = read();
    add(a,b);add(b,a);
  }
  dfs(q,0,-1);
  set_up_lca(n*2);
  for (int i=0;i<m;i++){
    int a,b;a = read(); b = read();
    printf("%d\n",LCA(a,b));
  }
}
