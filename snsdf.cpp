#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int graph[30][30];
bool visited[30][30];
int main(){
  int a,b,c; cin >> a >> b >> c;

  queue<pair<pair<int,int>,int> > q;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      char d; cin >> d;
      if (d == '(') graph[i][j] = b; else graph[i][j] = c;
    }
  }
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  visited[0][0] = true;
  for (int i=0;i<4;i++){
    if (x[i]>=0 && y[i]>=0){
      q.push(make_pair(make_pair(x[i],y[i]),graph[x[i]][y[i]]));
    }
  }
  int mini = 1000000;
  while(!q.empty()){
    visited[q.front().first.first][q.front().first.second] = true;
    mini = min(mini,q.front().second);
    for (int i=0;i<4;i++){
      if (q.front().first.first+x[i]>=0 &&
          q.front().first.second+y[i]>=0 &&
          q.front().first.first+x[i]<a &&
          q.front().first.second+y[i]<a){
            if (!visited[q.front().first.first+x[i]][q.front().first.second+y[i]]){
              q.push(make_pair(
                     make_pair(q.front().first.first+x[i],q.front().first.second+y[i])
                     ,q.front().second+graph[q.front().first.first+x[i]][q.front().first.second+y[i]]));
            }
          }
    }
    q.pop();
  }
  cout << mini;
}
