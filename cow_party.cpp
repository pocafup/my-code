#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
#define INF 200000000;

int dist[1000];
int visited[1000];
int cost[1000][1000];
int main(){
  int a,b,c; cin >> a >> b >> c;
  vector<pair<int,int> > road[a];
  for (int i=0;i<a;i++){
    int d,e,f; cin >> d >> e >> f;
    road[d].push_back(make_pair(e,f));
    cost[d][e] = f;
  }
  int maxi = 0;
  priority_queue<pair<int, int> > q;
  for (int i=0;i<a;i++){
    for (int j=0;j<1000;j++) dist[j] = INF;
    int local = 0;
    if (i!=c) q.push(make_pair(i,0));
    dist[i] = 0;
    visited[i] = true;
    while(!q.empty()){
      visited[q.top().first] = true;
      for (int j=0;j<road[q.top()].size();j++){
        if (!visited[road[q.top()][j].first]){

          dist[road[q.top()][j].first] = min(dist[road[q.top()][j].first],dist[q.top()]+cost[q.top()][road[q.top()][j].first]);
          q.push(road[q.top()][j].first,dist[road[q.top()]][j]);
        }
      }
      q.pop();
    }
    local = dist[c];
    maxi = max(local,maxi);
  }
  cout << maxi;
}
