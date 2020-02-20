#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 100005
long long n,m,ans = 1;
vector<long long> adj[2*MAXN];
bool vis[MAXN*2+5];
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

bool spfa(long long posi, bool vis[]){
  queue<long long> q;
  q.push(posi);
  vis[posi] = true;
  while (!q.empty()){
    long long qf = q.front();q.pop();
    for (long long v : adj[qf]){
      if (!vis[v]){
        vis[v] = true;
        q.push(v);
      }
    }
  }
  for (long long i=1;i<=n;i++) if (vis[i] && vis[i+n]) return false;
  return true;
}
void to_bin(long long num){
  long long rb = 20;
  queue<long long> q;
  while((1<<rb)>num) rb--;
  for (long long i=rb;i>=0;i--){
    if ((num>>i)&1) q.push(1);
    else q.push(0);
  }
  while(!q.empty()){
    cout<< q.front();
    q.pop();
  }
}
int main(){
  // setIO("revegetate");
  cin >> n >> m;
  for (long long i=0;i<m;i++){
    long long b,c;char a;cin >> a >> b >> c;
    if (a=='S'){
      adj[b].push_back(c);
      adj[c].push_back(b);
      adj[b+n].push_back(c+n);
      adj[c+n].push_back(b+n);
    }else{
      adj[b].push_back(c+n);
      adj[c+n].push_back(b);
      adj[c].push_back(b+n);
      adj[b+n].push_back(c);
    }
  }
  if (!spfa(1)){cout << 0; return 0;}
  
  cout << 1;
  for (long long i=1;i<=n;i++) if (!vis[i] && !vis[i+n]) cout << 0;
  cout << 0;
}
