#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int,int> > rd[50001];
int pos[10001];
int dist[10001][6];
int vis[10001];
void dijiksta(int aa,int bb){

  queue<pair<int,int> > q;
  dist[aa][bb] = 0;
  q.push(make_pair(aa,0));
  while(!q.empty()){
    int qf = q.front().first;
    int qs = q.front().second;
    q.pop();
    for (int i=0;i<rd[qf].size();i++){
      if(dist[rd[qf][i].first][bb]>qs+rd[qf][i].second){
        dist[rd[qf][i].first][bb] = qs+rd[qf][i].second;
        q.push(make_pair(rd[qf][i].first,qs+rd[qf][i].second));
      }
    }
  }
}
int a,b,c;
int dfs(int fir, int prev,int posi, bool vis[], int answ){
  vis[posi] = true;
  answ+=dist[prev][posi];
  // cout << "   " << fir << " " << prev << " " << posi << " " << answ << endl;
  for (int i=0;i<c;i++) cout << vis[i] << endl;
  // cout << "     " << answ << endl;
  int previous = answ;
  bool n = false;
  for (int i=0;i<c;i++){
    if (!vis[i]){
      vis[i] = true;
      n = true;
      if(answ!=previous) answ = min(answ,dfs(fir,posi,i,vis,previous));
      else answ = dfs(fir,posi,pos[i],vis,previous);
      vis[i] = false;
    }
  }
  if (!n) {answ+=dist[fir][posi];cout << "ans = " << answ << endl;}

  return answ;
}
int main(){
  cin >> a >> b >> c;
  bool visited[c];
  for (int i=0;i<c;i++) {cin >> pos[i];pos[i]--;}
  for (int i=0;i<b;i++){
    int d,e,f; cin >> d >> e >> f;
    d--;e--;
    rd[d].push_back(make_pair(e,f));
    rd[e].push_back(make_pair(d,f));
  }
  for (int i=0;i<c;i++){
    for (int j=0;j<a;j++){
      dist[j][i] = 1e8;
    }
  }
  for (int i=0;i<c;i++) dijiksta(pos[i],i);
  for (int i=0;i<c;i++){
    for (int j=0;j<a;j++){
      cout << dist[j][i] << " ";
    }
    cout << endl;
  }
  int ans = 1e8;

  for (int i=0;i<a;i++){
    bool cont = false;
    for (int j=0;j<c;j++){
      if (pos[j]==i) cont = true;
    }
    if (cont) continue;
    for (int j=0;j<c;j++){
      memset(visited,0,sizeof(visited));
      ans = min(ans,dfs(i,i,j,visited,0));
      // cout << "   ans   " << ans << endl;
    }
  }
  cout << ans;
}
