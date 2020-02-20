#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
pp st;
int n,m,maxi = 0,ct,dist[55][55];
char grid[55][55];
int x[4] = {1,0,-1,0};
int y[4] = {0,-1,0,1};
bool check(pp a, int k){
  return a.f+x[k]>=0 && a.f+x[k]<n && a.s+y[k]>=0 && a.s+y[k]<m;
}
bool vis[55][55];
void spfa(pp start){
  int ans = 0;
  queue<pp> q;
  q.push(start);
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      dist[i][j] = -1;
      // cout << dist[i][j] << " ";
    }
    // cout << endl;
  }
  dist[start.f][start.s] = 0;

  while(!q.empty()){
    int qf = q.front().f,qs = q.front().s; q.pop();
    // cout << qf << " " << qs << endl;
    vis[qf][qs] = false;
    for (int i=0;i<4;i++){
      if (check(make_pair(qf,qs),i)){
        int dis,to_x = qf+x[i],to_y = qs+y[i];
        // cout << grid[to_x][to_y] << "   ??   " << dist[to_x][to_y] << endl;

        if (grid[to_x][to_y]=='$' || grid[qf][qs]=='$' || grid[qf][qs]=='X' || grid[to_x][to_y]=='X') dis = 2;
        else if ((int)grid[to_x][to_y]-(int)grid[qf][qs]==0) dis = 1;
        else if (abs((int)grid[to_x][to_y]-(int)grid[qf][qs])==1) dis = 3;
        else continue;
        // cout << "dis " << dis << endl;
        if (dist[to_x][to_y]>dist[qf][qs]+dis || dist[to_x][to_y]==-1){
          dist[to_x][to_y] = dist[qf][qs]+dis;
          if (!vis[to_x][to_y]) { vis[to_x][to_y] = true; q.push(make_pair(to_x,to_y));}
        }
      }
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (dist[i][j]==-1 && grid[i][j]=='$') {cout << -1 << endl; return;}
      if (grid[i][j]=='$') {maxi = max(maxi,dist[i][j]);ans += dist[i][j];}
    }
  }
  cout << ans*2-maxi << endl;
}
int main(){
  int T; cin >> T;
  while(T--){
    cin >> n >> m;
    maxi = 0,ct = 0;
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        dist[i][j] == -1;
      }
    }
    for (int i=0;i<n;i++){
      // for (int j=0;j<m;j++){
      string s; cin >> s;
      for (int j=0;j<m;j++){
        grid[i][j] = s[j];
        if (s[j]=='X') st = make_pair(i,j);
        if (s[j]=='$') ct++;
      }
    }
    spfa(st);
  }
}
