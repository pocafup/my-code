#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;
#define pp pair<int,int>
bool vis[202][202];
int main(){
  ifstream cin ("pails.in");
  ofstream cout ("pails.out");
  int x,y,k,m; cin >> x >> y >> k >> m;
  queue<pair<pp,int> > q;
  q.push(make_pair(make_pair(0,0),0));
  int ans = 1e9;
  while(!q.empty()){
    int qff = q.front().first.first;
    int qfs = q.front().first.second;
    int qs = q.front().second;
    q.pop();
    // cout << abs(m-qff) << " " << abs(m-qfs) << " " << qs << endl;

    ans = min(ans,abs(qff+qfs-m));
    if (k==qs) continue;

    if (!vis[0][qfs]){
      q.push(make_pair(make_pair(0,qfs),qs+1));
      vis[0][qfs] = true;
    }
    if (!vis[x][qfs]){
      q.push(make_pair(make_pair(x,qfs),qs+1));
      vis[x][qfs] = true;
    }
    if (!vis[qff][y]){
      q.push(make_pair(make_pair(qff,y),qs+1));
      vis[qff][y] = true;
    }
    if (!vis[qff][0]){
      q.push(make_pair(make_pair(qff,0),qs+1));
      vis[qff][0] = true;
    }
    if (qfs+qff<=y && !vis[0][qfs+qff]){
      vis[0][qfs+qff] = true;
      q.push(make_pair(make_pair(0,qfs+qff),qs+1));
    }
    if (qfs+qff>y && !vis[qff+qfs-y][y]){
      vis[qff+qfs-y][y] = true;
      q.push(make_pair(make_pair(qff+qfs-y,y),qs+1));
    }
    if (qfs+qff<=x && !vis[qfs+qff][0]){
      vis[qfs+qff][0] = true;
      q.push(make_pair(make_pair(qfs+qff,0),qs+1));
    }
    if (qfs+qff>x && !vis[x][qfs+qff-x]){
      vis[x][qfs+qff-x] = true;
      q.push(make_pair(make_pair(x,qfs+qff-x),qs+1));
    }
  }
  cout << ans;
}
