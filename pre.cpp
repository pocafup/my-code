#include <iostream>
#include <queue>

using namespace std;

void solve(){
  queue<pair<int,int> > q;
  int a,b;
  cin >> a >> b;
  char x[a][b];
  int y[a][b];
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> x[i][j];
      if (x[i][j] == '.'){
        y[i][j] = 0;
      }else{
        y[i][j] = 1;
      }
    }
  }
  int varx[4] = {-1,0,1,0};
  int vary[4] = {0,-1,0,1};
  int plot = 2;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      if (y[i][j] == 1){
        y[i][j] = plot;
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
              if (y[varx[k]+q.front().first][vary[k]+q.front().second] == 1){
                y[varx[k]+q.front().first][vary[k]+q.front().second] = plot;
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
    for (int j=0;j<b;j++){
      cout << y[i][j];
    }
    cout << endl;
  }
}

int main(){
  solve();
}
