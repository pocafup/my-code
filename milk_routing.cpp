#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <math.h>

using namespace std;

int n,m;
double x;
struct node{
  int from,to,next;
  double dis,lag;
}road[100001];
double max(double a, double b){
  if (a>b) return a;
  return b;
}
pair<double,double> dist[501];
int tot = 0, head[100001];
queue<int> q;
void add(int a, int b ,double c, double d){
  road[++tot].from = a;
  road[tot].to = b;
  road[tot].lag = c;
  road[tot].dis = x/d;
  road[tot].next = head[a];
  head[a] = tot;
}
int main(){
  cin >> n >> m >> x;
  for (int i=0;i<m;i++){
    int a,b;double c,d; cin >> a >> b >> c >> d;
    add(a,b,c,d);
    add(b,a,c,d);
  }
  for (int i=0;i<=n;i++) dist[i] = make_pair(10000000,0);
  dist[1] = make_pair(0,0);
  q.push(1);
  while(!q.empty()){
    int qf = q.front();q.pop();
    for (int i=head[qf];i;i=road[i].next){
      // cout << road[i].to << endl;
      // cout << road[i].dis << " " << road[i].lag << " "<< dist[road[i].from].second << endl;
      if (dist[road[i].to].first>dist[road[i].from].first+road[i].lag+max(0,road[i].dis-dist[road[i].from].second)){
        dist[road[i].to].first=dist[road[i].from].first+road[i].lag+max(0,road[i].dis-dist[road[i].from].second);
          // cout << dist[road[i].from].first << " " << road[i].lag << " " << road[i].dis << endl;
        // cout << "maxi " << max(0,road[i].dis-dist[road[i].from].second) << endl;
        // cout << dist[road[i].to].first << endl;
        dist[road[i].to].second = max(dist[road[i].from].second,road[i].dis);
        q.push(road[i].to);
      }
    }
    // for (int i=0;i<=n;i++) cout << dist[i].first << " ";
    // cout << endl;

  }
  cout << (int)dist[n].first;
}
