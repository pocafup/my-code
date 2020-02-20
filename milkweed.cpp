#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(){
  int a,b,c,d;
  queue<pair<int,int> > q;
  cin >> a >> b >> c >> d;
  d = b-d;
  c--;
  char x[b][a];
  bool visited[1000][1000];
  memset(visited,0,sizeof(visited));
  for (int i=0;i<b;i++){
    for (int j=0;j<a;j++){
      cin >> x[i][j];
      if (x[i][j] != '.'){
        visited[i][j] = true;
      }
    }
  }
  cout << "aa" << endl;
  x[d][c] = 'M';
  for (int i=0;i<b;i++){
    for (int j=0;j<a;j++){
      cout <<  x[i][j];
    }
    cout << endl;
  }
  pair<int,int> s;
  s.first = c;
  s.second = d;
  q.push(s);
  int varx[8] = {-1,0,1,0,-1,-1,1,1};
  int vary[8] = {0,-1,0,1,1,-1,1,-1};
  int tt = 1;
  int times = 0;
  while (!q.empty()){
    visited[q.front().first][q.front().second] = true;
    for (int k=0;k<8;k++){
      if (varx[k]+q.front().first >= 0 && varx[k]+q.front().first < a && vary[k]+q.front().second >= 0 && vary[k]+q.front().second < b){
        if (visited[varx[k]+q.front().first][vary[k]+q.front().second] == false){
          pair<int,int> s2;
          s2.first = varx[k]+q.front().first;
          s2.second = vary[k]+q.front().second;
          q.push(s2);

        }
      }
    }
    q.pop();
    tt--;
    if(tt == 0){
      tt = q.size();
      times++;
    }

  }
  cout << times-2;
}
