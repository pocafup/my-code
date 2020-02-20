#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define pp pair<int,int>
int x[8] = {1,1,1,0,-1,-1,-1,0};
int y[8] = {1,0,-1,-1,-1,0,1,1};
int w,l,ct=0,ans = 0;
bool vis[10][55];
char grid[10][55];
int dp[10][55][305];
vector<pp> path[10][55];
map<int,int> mp;
bool check(int x_pos, int y_pos, int k){
  return x_pos+x[k]>=0 && x_pos+x[k]<w && y_pos+y[k]>=0 && y_pos+y[k]<l;
}
bool dfs(int x_pos, int y_pos, int carry){

  if (x_pos==w-1 && y_pos==l-1 && carry==ct) {ans = (ans+1)%10000; return true;}
  for (int i=0;i<8;i++){
    if (check(x_pos,y_pos,i)){
      int go_x = x_pos+x[i],go_y = y_pos+y[i];
      if (grid[go_x][go_y]=='.') continue;
      if (grid[go_x][go_y]=='X' && !vis[go_x][go_y]){
        vis[go_x][go_y] = true;
        dfs(go_x,go_y,carry);
        vis[go_x][go_y] = false;
      }
      if (grid[go_x][go_y]=='S' && !vis[go_x][go_y]){
        vis[go_x][go_y] = true;
        dfs(go_x,go_y,carry+1);
        vis[go_x][go_y] = false;
      }
    }
  }
}
int main(){
  cin>> w >> l;
  for (int i=0;i<w;i++){
    for (int j=0;j<l;j++){
      cin >> grid[i][j];
      if (grid[i][j] == 'S') ct++;
    }
  }
  vis[0][0] = true;
  queue<pair<pp,pair<int,vector<pp> > > > q;
  dp[0][0][0] = 1;
  vector<pp> vec;
  if (grid[0][0]=='S') vec.push_back(make_pair(0,0));
  q.push(make_pair(make_pair(0,0),((grid[0][0]=='S')?1:0),vec);
  while(!q.empty()){
    int qff = q.front().first,qsf = q.front().second, qs = q.front().second.second;
    vector<int> temp = q.front().second.second;
    q.pop();
    for (int i=0;i<8;i++){
        if (check(qff,qfs,i)){
          int go_x = qff+x[i],go_y = qfs+y[i];
          if (grid[go_x][go_y]=='.') continue;
          if (grid[go_x][go_y]=='X' && !vis[go_x][go_y]){
            vis[go_x][go_y] = true;
            vis[go_x][go_y] = false;
          }
          if (grid[go_x][go_y]=='S' && !vis[go_x][go_y]){
            vis[go_x][go_y] = true;
            dfs(go_x,go_y,carry+1);
            vis[go_x][go_y] = false;
          }
        }
      }
  }
  // dfs(0,0,((grid[0][0]=='S')?1:0));
  cout << ans;
}
