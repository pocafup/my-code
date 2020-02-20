#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
#define INF 200000000;
int well[300];
int graph[300][300];
int dist[300];
int main(){
  int a; cin >>a ;
  for (int i=0;i<a;i++) cin >> well[i];
  for (int i=0;i<a;i++)
    for (int j=0;j<a;j++)
      cin >> graph[i][j];

  priority_queue<pair<int,int > > q;
  int mini = INF;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++) dist[j] = INF;
    dist[i] = 0;
    q.push(make_pair(i,dist[i]));
    while(!q.empty()){
      for (int j=0;j<a;j++){
        dist[j] = min(dist[j],graph[i][j]);
      }
      q.pop();
    }
    int local = 0;
    for (int j=0;j<a;j++) cout << dist[j] << " ";
    cout << endl;
    for (int j=0;j<a;j++) local += dist[j];
    local += jn;
    mini = min(mini,local);
  }
  cout << mini;
}
