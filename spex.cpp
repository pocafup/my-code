#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
  int a;cin >> a ;
  bool visited[1000][1000];
  char e[1000][1000];
  int  b[1000][1000];
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

        q.push(make_pair(i,j));
        while(!q.empty()){
          int qf = q.front().first;
          int qs = q.front().second;
          q.pop();
          visited[qf][qs] = true;
          for(int k=0;k<4;k++){
            if (varx[k]+qf >= 0 && varx[k]+qf < a && vary[k]+qs >= 0 && vary[k]+qs < a){
              if (b[varx[k]+qf][vary[k]+qs] == 1 && visited[varx[k]+qf][vary[k]+qs] == false){
                b[varx[k]+qf][vary[k]+qs] = plot;
                q.push(make_pair(varx[k]+qf,vary[k]+qs));
              }
            }
          }
        }

        plot++;
      }
    }
  }

  cout << plot-1;
}
