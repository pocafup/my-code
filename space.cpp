#include <iostream>
#include <queue>

using namespace std;

void solve(){

  int a;
  cin >> a ;
  bool visited[a][a];
  char e[a][a];
  int  b[a][a];
  memset(visited,0,sizeof(visited));
  memset(b,0,sizeof(b));
  memset(e,0,sizeof(e));
  queue<pair<int,int> > q;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cin >> e[i][j];
      if (e[i][j] == '*'){
        b[i][j] = 1;
      }else{
        b[i][j] = 0;
      }
    }
  }

  int plot = 1;
  int varx[4] = {-1,0,1,0};
  int vary[4] = {0,-1,0,1};
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (b[i][j] == 1 && visited[i][j] == false){
        b[i][j] = plot;
        visited[i][j] = true;
        pair<int,int> start;
        start.first = i;
        start.second = j;
        q.push(start);
        while(!q.empty()){
          visited[q.front().first][q.front().second] = true;
          for(int k=0;k<4;k++){
            if (varx[k]+q.front().first >= 0 && varx[k]+q.front().first < a && vary[k]+q.front().second >= 0 && vary[k]+q.front().second < a){
              if (b[varx[k]+q.front().first][vary[k]+q.front().second] == 1 && visited[varx[k]+q.front().first][vary[k]+q.front().second] == false){
                b[varx[k]+q.front().first][vary[k]+q.front().second] = plot;
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
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout << b[i][j];
    }
    cout << endl;
  }
  cout << plot-1;





}












int main(){
  solve();
}
