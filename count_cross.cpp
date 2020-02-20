#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define pp pair<int,int>
int x[4] = {1,0,-1,0};
int y[4] = {0,1,0,-1};
int n,m,r,grid[105][105],ans = 0;
bool vis[105][105],go[105][105][4],cow[105][105];
vector<pp> re;
queue<pp> q;
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}
bool check(pp a, int b){
  return a.first+x[b]>0 && a.first+x[b]<=n && a.second+y[b]>0 && a.second+y[b]<=n;
}
void solve(int a, int b){
  vis[a][b] = true;
  int curr = 0;
  q.push(make_pair(a,b));
  while(!q.empty()){
    int qf = q.front().first, qs = q.front().second;
    if (cow[qf][qs]) curr++;
    q.pop();
    for (int i=0;i<4;i++){
      if (check(make_pair(qf,qs),i)){
        if (!go[qf][qs][i] && !vis[qf+x[i]][qs+y[i]]){
          vis[qf+x[i]][qs+y[i]]= true;
          q.push(make_pair(qf+x[i],qs+y[i]));
        }
      }
    }
  }
  ans+=m-curr;
  // cout << curr << endl;
}
int main(){
  // setIO("countcross");
  cin >> n >> m >> r;
  for (int i=0;i<r;i++){
    int a,b,c,d; cin >> a >> b >> c >> d;
    for (int j=0;j<4;j++){
      if (a+x[j]==c && b+y[j]==d){
        go[a][b][j] = true;
        go[c][d][(j+2)%4] = true;
      }
    }
  }
  for (int i=0;i<m;i++){
    int a,b; cin >> a >> b;
    cow[a][b] = true;
    re.push_back(make_pair(a,b));
  }
  for (int i=0;i<re.size();i++){
    memset(vis,0,sizeof(vis));
    solve(re[i].first,re[i].second);
  }
  cout << ans/2;
}
