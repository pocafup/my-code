#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
int n,m;
vector<pp> island[20];
char grid[55][55];
int grid2[55][55],ans = 1e9;
bool vis[55][55];
int dist[20][20];
int dp[(1<<20)][20];
queue<pp> q;
int curr = 0,visit[55][55];
int x_[4] = {1,0,-1,0};
int y_[4] = {0,-1,0,1};
bool check(int x, int y ,int k){
  return x+x_[k]<n && x+x_[k]>=0 && y+y_[k]<m && y+y_[k]>=0;
}
void init(int x, int y){
  vis[x][y] = true;
  curr++;
  q.push(make_pair(x,y));
  while(!q.empty()){
    int qf = q.front().f,qs = q.front().s;q.pop();
    island[curr].push_back(make_pair(qf,qs));
    grid2[qf][qs] = curr;
    for (int k=0;k<4;k++){
      if (check(qf,qs,k)){
        int to_x = qf+x_[k], to_y = qs+y_[k];
        if (!vis[to_x][to_y] && grid[to_x][to_y]=='X'){
          vis[to_x][to_y] = true;
          q.push(make_pair(to_x,to_y));
        }
      }
    }
  }
}
queue<pair<pp,int> > q2;

void init_queue(int pos){
  for (pp i : island[pos]) {visit[i.f][i.s] = true;vis[i.f][i.s] = true;q2.push(make_pair(i,0));}
}
void flood_fill(int pos){
  while(!q2.empty()){
    int qf = q2.front().f.f,qs = q2.front().f.s,qss = q2.front().s;q2.pop();
    for (int i=0;i<4;i++){
      if (check(qf,qs,i)){
        int to_x = qf+x_[i], to_y = qs+y_[i],to_grid =  grid2[to_x][to_y];
        int addi = (grid2[to_x][to_y]==-1) ? 1 : 0;
        if (to_grid!=0){
          if (to_grid!=pos && to_grid!=-1) {
            if (dist[pos][to_grid]>qss+addi){
              visit[to_x][to_y] = qss+addi;
              dist[pos][to_grid] = qss+addi;
              q2.push(make_pair(make_pair(to_x,to_y),qss+addi));
            }
            else if (!visit[to_x][to_y] ||qss+addi<visit[to_x][to_y]) {
              visit[to_x][to_y] = qss+addi;
              q2.push(make_pair(make_pair(to_x,to_y),qss+addi));
            }
          }else if (to_grid==-1 && (!visit[to_x][to_y] || visit[to_x][to_y]>qss+addi)){
            visit[to_x][to_y] = qss+addi;
            q2.push(make_pair(make_pair(to_x,to_y),qss+addi));
          }
        }
      }
    }
  }
}
int main(){
  cin >> n >> m;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> grid[i][j];
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (grid[i][j]=='.') grid2[i][j] = 0;
      else if (grid[i][j]=='S') grid2[i][j] = -1;
      else if (!vis[i][j]){
        init(i,j);
      }
    }
  }
  memset(dist,0x3f3f,sizeof(dist));
  memset(vis,0,sizeof(vis));
  for (int i=0;i<=15;i++) dist[i][i] = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (!vis[i][j] && grid2[i][j]>0){
        memset(visit,0,sizeof(visit));
        init_queue(grid2[i][j]);
        flood_fill(grid2[i][j]);
      }
    }
  }
  memset(dp,0x3f3f,sizeof(dp));
  for (int i=1;i<=curr;i++) dp[(1<<(i-1))][i] = 0;
  for (int i=1;i<(1<<curr);i++){
    for (int k=curr;k>0;k--){
      if ((i>>(k-1))&1){
        for (int j=1;j<=curr;j++){
          if (!((i>>(j-1))&1)){
            dp[i+(1<<(j-1))][j] = min(dp[i+(1<<(j-1))][j],dp[i][k]+dist[k][j]);
          }
        }
      }
    }
  }
  for (int i=1;i<=curr;i++) ans = min(ans,dp[(1<<curr)-1][i]);
  cout << ans;
}
