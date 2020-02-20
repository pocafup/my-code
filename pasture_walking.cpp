#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define pp pair<int,int>
int dist[1001];
int n,q;
vector<pp> vec[1001];
// struct node{
//   int from,to,dis;
// }edge[2005];
// int tot = 0;
// void add
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
    for (int i=0;i<vec[qf].size();i++){
      if (dist[vec[qf][i].first]>dist[qf]+vec[qf][i].second){
        dist[vec[qf][i].first]=dist[qf]+vec[qf][i].second;
        q.push(vec[qf][i].first);
      }
    }
  }

  return dist[to];
}
int main(){
  cin >> n >> q;
  for (int i=0;i<n-1;i++){
    int a,b,c; cin >> a >> b >> c;
    vec[a].push_back(make_pair(b,c));
    vec[b].push_back(make_pair(a,c));
  }
  for (int i=0;i<q;i++){
    int d,e; cin >> d >> e;
    cout << dijkstra(d,e) << endl;
  }
}
