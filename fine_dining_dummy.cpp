#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;
#define pp pair<int,int>
int dis1[50001];
int dis2[50001];
int cnt = 0;
int head[300005];
int vis[50001];
vector<pp> vec[50005];
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
struct Node{
    int nxt,to,w;
}edge[300005];
void add(int x,int y,int w){
    edge[++cnt].nxt=head[x];
    edge[cnt].w=w;
    edge[cnt].to=y;
    head[x]=cnt;
}
void dijkstra(int pos){
  memset(dis1,0x3f3f,sizeof(dis1));
  dis1[pos] = 0;
  queue<int> q;
  q.push(pos);
  memset(vis,0,sizeof(vis));
  while(!q.empty()){
    int qf = q.front();
    q.pop();
    vis[qf] = 0;
    for (int i=head[qf];i;i=edge[i].nxt){
      if (dis1[edge[i].to]>dis1[qf]+edge[i].w){
        dis1[edge[i].to]=dis1[qf]+edge[i].w;
        if (!vis[edge[i].to]){
          vis[edge[i].to] = true;
          q.push(edge[i].to);
        }
      }
    }
  }
}
int main(){
  ifstream cin ("dining.in");
  ofstream cout ("dining.out");
  int a,b,c; cin >> a >> b >> c;
  for (int i=0;i<b;i++){
    int d,e,f; cin >> d >> e >> f;
    // vec[d].push_back(make_pair(e,f));
    // vec[e].push_back(make_pair(d,f));
    add(d,e,f);
    add(e,d,f);
  }
  dijkstra(a);
  for (int i=0;i<=a;i++) dis2[i] = dis1[i];

  for (int i=0;i<c;i++){
    int d,e; cin >> d >> e;
    add(a+1,d,dis2[d]-e);
    //vec[a+1].push_back(make_pair(d,dis2[d]-e));
  }
  dijkstra(a+1);
  for (int i=1;i<a;i++){
    cout << (dis1[i]<=dis2[i]) << endl;
  }
}
