#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int grid[101][101];
bool visited[101][101][15];
queue<pair<pair<int,int>,int> > q;
int main(){
  int a,b,c; cin >> a >> b >> c;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      char d; cin >> d;
      if (d == '.') grid[i][j] = 0;
      else grid[i][j] = 1;
    }
  }
  int p1,p2,p3,p4; cin >> p1 >> p2 >> p3 >> p4;
  p1--;p2--;p3--;p4--;
  q.push(make_pair(make_pair(p1,p2),0));
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  int ans = 0;
  while(!q.empty() && q.front().second<=c){

    int qf = q.front().first.first;
    int qs = q.front().first.second;
    visited[qf][qs][q.front().second] = true;
    if (qf==p3 && qs == p4 && q.front().second==c) ans++;
    for (int i=0;i<4;i++){
      if (qf+x[i]>=0 && qf+x[i]<a && qs+y[i]>=0 && qs+y[i]<b){
        if (!visited[qf+x[i]][qs+y[i]][q.front().second]){
          if (grid[qf+x[i]][qs+y[i]]!=1){
            q.push(make_pair(make_pair(qf+x[i],qs+y[i]),q.front().second+1));
          }
        }
      }
    }
    q.pop();
    //cout << ans << " " << q.front().second << endl;
  }
  cout << ans;
}
