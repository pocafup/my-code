#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n,m,k;
int toll[255],head[100005],dist[255][255];
struct Edge{
  int from,to,dis,next;
}edge[100005];
int tot = 0;
void add(int a, int b, int c){
  edge[++tot].from = a;
  edge[tot].to = b;
  edge[tot].dis = c;
  edge[tot].next = head[a];
  head[a] = tot;
}
void dij(int pos){
  dist[pos][pos] = 0;
  queue<int> q;
  q.push(pos);
  while(!q.empty()){
    int qf = q.front();q.pop();
    for (int i=head[qf];i;i=edge[i].next){
      int t = edge[i].to;
      if (dist[pos][t]>dist[pos][qf]+edge[i].dis+toll[t]){
        dist[pos][t] = dist[pos][qf]+edge[i].dis+toll[t];
        q.push(t);
      }
    }
  }

}
int main(){
  cin >> n >> m >> k;
  memset(dist,0x3f3f,sizeof(dist));
  for (int i=1;i<=n;i++) cin >> toll[i];
  for (int i=0;i<m;i++){
    int a,b,c; cin >> a >> b >> c;
    add(a,b,c); add(b,a,c);
  }
  for (int i=1;i<=n;i++) dij(i);
  for (int i=0;i<k;i++){
    int a,b; cin >> a >> b; cout << dist[a][b] << endl;
  }
}
