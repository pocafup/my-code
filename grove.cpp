#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int graph[50][50];
bool visited[50][50];
int dist[50][50];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      char c; cin >> c;
      if (c == 'X') graph[i][j] = 1;
      if (c == '.') graph[i][j] = 0;
      if (c == '*') graph[i][j] = 2;
    }
  }
  queue<pair<int,int> > fq;
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      if (graph[i][j] == 1 && visited[i][j] == false){
        visited[i][j] = true;
        q.push_back(make_pair(i,j)){
          while(!q.empty()){
            int qf = q.front().first;
            int qs = q.front().second;
            for (int i=0;i<4;i++){
              if (qf+x[i]>=0 && qs+y[i]>=0 && qf+x[i]<a && qs+y[i]<b){
                if (visited[qf+x[i]][qs+y[i]]){

                }
              }
            }
          }
        }
      }
    }
  }
}
