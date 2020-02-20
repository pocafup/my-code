#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;
#define pp pair<int,int>
vector<int> vec[105];
bool vis[105];
int sz;
void bfs(int pos){
  vis[pos] = 1;
  for (int i = 0;i<vec[pos].size();i++){
    if (!vis[vec[pos][i]]){
      vis[vec[pos][i]] = true;
      bfs(vec[pos][i]);
      sz++;
    }
  }
  return;
}
// void setIO(string name) {
// 	freopen((name+".in").c_str(),"r",stdin);
// 	freopen((name+".out").c_str(),"w",stdout);
// 	ios_base::sync_with_stdio(0);
// }

int main(){
  // setIO("factory");
  int n; cin >> n;
  for (int i=0;i<n-1;i++) {int a,b; cin >> a >> b; vec[b].push_back(a);}
  for (int i=1;i<=n;i++){
    memset(vis,0,sizeof(vis));
    sz = 1;
    bfs(i);
    if (sz>=n) {cout << i; exit(0);}
  }
  cout << -1;
}
