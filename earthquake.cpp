#include <iostream>
#include <algorithm>

using namespace std;
int p,c,n,tot = 0,head[500005];
struct Edge{
  int from,to,next;
}edge[500005];
int posible[500005];
void add(int f, int t){
  edge[++tot].from = f;
  edge[tot].to = t;
  edge[tot].next = head[f];
  head[f] = tot;
}
int ans = 0;
bool vis[500005];
void dfs(int pos){
  ans++;vis[pos] = true;
  for (int i=head[pos];i;i=edge[i].next){
    if (posible[edge[i].to] && !vis[edge[i].to]) dfs(edge[i].to);
  }
}
int main(){
  cin >> p >> c >> n;
  for (int i=1;i<=p;i++)posible[i] = true;
  for (int i=0;i<c;i++){
    int a,b; cin >> a >> b;
    add(a,b); add(b,a);
  }
  for (int i=0;i<n;i++){
    int a; cin >> a;
    posible[a] = false;
    for (int j=head[a];j;j=edge[j].next){
      posible[edge[j].to] = false;
    }
  }
  dfs(1);
  cout << p-ans;
}
