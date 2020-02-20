#include <iostream>
#include <queue>

using namespace std;

void solve(){
  int a,b;
  int x,y;
  bool visited[100000][100000];
  memset(visited,0,sizeof(visited));
  queue<pair<int,int> > q;
  cin >> a >> b;
  char e[a][b];
  int maze[a][b];

  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> e[i][j];
      if (e[i][j] == 'X'){
        maze[i][j] = 1;
      }else{
        maze[i][j] = 0;
      }
    }
  }
  int varx[4] = {-1,0,1,0};
  int vary[4] = {0,-1,0,1};
  memset(maze,0,sizeof(maze));
  pair<int,int> d[a];
  for (int i=0;i<a;i++){
    cin >>d[i].first >> d[i].second;
    maze[d[i].first-1][d[i].second-1] = 1;
  }

  int plot = 2;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (maze[i][j] == 1){
        maze[i][j] = plot;
        pair<int,int> start;
        start.first = i;
        start.second = j;
        q.push(start);
        while(!q.empty()){
          for(int k=0;k<4;k++){
            if (varx[k]+q.front().first >= 0 && varx[k]+q.front().first < a && vary[k]+q.front().second >= 0 && vary[k]+q.front().second < b){

              if (maze[varx[k]+q.front().first][vary[k]+q.front().second] == 1){
                maze[varx[k]+q.front().first][vary[k]+q.front().second] = plot;
                pair<int,int> s;
                s.first = varx[k]+q.front().first;
                s.second = vary[k]+q.front().second;
                q.push(s);
              }
            }
          }
          q.pop();
        }

        plot++;
      }
    }
    cout << endl;
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cout << maze[i][j];
    }
  }

}












int main(){
  solve();
}
