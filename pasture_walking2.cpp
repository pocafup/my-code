#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define pp pair<int,int>
#define ri register int
template <typename T>inline void redi(T& t)
{
    ri c=getchar();t=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))t=t*10+c-48,c=getchar();
}
template <typename T,typename... Args> inline void redi(T& t, Args&... args)
{
    redi(t);redi(args...);
}
int dist[1001],head[2005];
int n,q;
struct node{
  int from,to,dis,next;
}edge[2005];
int tot = 0;
void add(int x, int y ,int z){
  edge[++tot].from = x;
  edge[tot].to = y;
  edge[tot].dis = z;
  edge[tot].next = head[x];
  head[x] = tot;
}
int len = 0;
int dijkstra(int from,int to){
  memset(dist,0x3f3f,sizeof(dist));
  dist[from] = 0;
  queue<int> q;
  q.push(from);
  while(!q.empty()){
    len++;
    int qf = q.front();
    q.pop();
    for (ri i=head[qf];i;i=edge[i].next){
      if (dist[edge[i].to]>dist[qf]+edge[i].from){
        dist[edge[i].to]=dist[qf]+edge[i].dis;
        q.push(edge[i].to);
      }
    }
  }

  return dist[to];
}
int main(){
  redi(n,q);
  for (int i=0;i<n-1;i++){
    int a,b,c; redi(a,b,c);
    add(a,b,c);
    add(b,a,c);
  }
  for (int i=0;i<q;i++){
    int d,e; redi(d,e);
    cout << dijkstra(d,e) << endl;
  }
}
