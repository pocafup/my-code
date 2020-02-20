#include <iostream>
#include <queue>

using namespace std;

void solve(){
  int a,b,c;
  int x,y;
  queue<pair<int,int> > q;
  cin >> a >> b >> c;
  int maze[a][b];
  int varx[4] = {-1,0,1,0};
  int vary[4] = {0,-1,0,1};
  memset(maze,0,sizeof(maze));
  pair<int,int> d[c];
  for (int i=0;i<c;i++){
    cin >>d[i].first >> d[i].second;
    maze[d[i].first-1][d[i].second-1] = 1;
  }

  int plot = 2;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      if (maze[i][j] == 1){
        maze[i][j] = plot;
        pair<int,int> start;
        start.first = i;
        start.second = j;
        q.push(start);
        while(!q.empty()){
          for(int k=0;k<4;k++){
            if (varx[k]+q.front().first >= 0 && varx[k]+q.front().first < a && vary[k]+q.front().second >= 0 && vary[k]+q.front().second < b){
              // cout << q.front().first << " " << q.front().second << endl;
              // cout << varx[k] << " " << vary[i] << endl;
              // cout << varx[i]+q.front().first << " " << vary[i]+q.front().second << "      " << k << endl;
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
  int maxi = 0;
  int res[100];
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      res[maze[i][j]]++;
      if (res[maze[i][j]] > maxi && maze[i][j] != 0){
        maxi = res[maze[i][j]];
      }
    }
    cout << endl;
  }
  cout << maxi;
}












int main(){
  solve();
}
