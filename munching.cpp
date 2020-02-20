#include <iostream>
#include <string>
#include <queue>

using namespace std;
bool visited[101][101];
int pos1,pos2;
queue<int> d;
queue<int> e;
queue<int> dis;
int main(){
  d.push(0);
  e.push(0);
  dis.push(0);
  visited[0][0] = true;
  int a,b;
  cin >> a >> b;
  string c[a][b];
  string r[a];
  int para[4] = {1,-1,0,0};
  int hori[4] = {0,0,1,-1};
  for (int i=0; i<a;i++){
    cin >> r[i];
  }
  for (int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      if (r[i][j] == 'C'){
          pos1 = i;
          pos2 = j;
      }
    }
  }

  int count = 1;
  cout << pos1 << " " << pos2 << endl;
  while (d.front()!=pos1 || e.front()!=pos2){
    int x = d.front();
    int y = e.front();
    int distance = dis.front();
    d.pop();
    e.pop();
    dis.pop();

    for(int i=0;i<4;i++){
      if (x+para[i] >=0 && x+para[i]< a
      && y+hori[i]>=0 && y+hori[i]<b &&
      (r[x+para[i]][y+hori[i]]=='.' || r[x+para[i]][y+hori[i]]=='C') &&
      visited[x+para[i]][y+hori[i]]== false){
        d.push(x+para[i]);
        e.push(y+hori[i]);
        visited[x+para[i]][y+hori[i]] = true;
        dis.push(distance+1);
      }
    }
  }
  cout << dis.front();
}
