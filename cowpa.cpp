#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 200000000;
bool visited[1000];
int road[1000][1000];
int dist[1000];
int main(){
  int a,b,c; cin >> a >> b  >> c;
  vector<int> vec[a];
  for (int i=0;i<b;i++){
    int d,e,f; cin >> d >> e >> f;
    road[d][e] = f;
    vec[d].push_back(e);
  }
  priority_queue<pair<int,int> > q;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++) {dist[j] = INF; visited[j]=false;}
    visited[i] = true;
    dist[i] = 0;
    q.push(i,0);
    while(!q.empty()){
      for (int k=0;k<vec[q.top()].size();k++){
        if(!visited[q.top()]){

        }
      }
    }
  }
}
