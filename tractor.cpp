#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int pos[501][501];
bool visited[501][501];
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++)
    for (int j=0;j<a;j++)
      cin >> pos[i][j];

  queue<pair<int,int> > q;
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      memset(visited,0,sizeof(visited));
      q.push(make_pair(i,j));
      visited[i][j] = true;
      while(!q.empty()){

      }
    }
  }
}
