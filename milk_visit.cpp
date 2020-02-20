#include <iostream>
#include <algorithm>

using namespace std;
int n,m,tot=0,head[100005],size[100005],fat[100005],level[100005];
struct Edge{
  int from,to,next;
}edge[200005];
void add(int f, int t){
  edge[++tot].from = f;
  edge[tot].to = t;
  edge[tot].next = head[f];
  head[f] = tot;
}
void dfs(int pos, int fa){
  size[pos] = 1;
  fat[pos] = fa;
  level[pos] = level[fa]+1;
  for (int i=head[pos];i;i=edge[i].next){
    int t = edge[i].to;
    if (t!=fa) dfs(t,pos);
    size[pos]+=size[t];
    if (size[son[pos]]<size[t]) son[pos] = t;
  }
}

void hld(int pos, int )
int main(){
  cin >> n >> m;
  for (int i=1;i<=n;i++) cin >> pos[i];
  for (int i=0;i<n-1;i++){
    int a,b; cin >> a >> b;
    add(a,b);add(b,a);
  }
  dfs(1,0);

}
