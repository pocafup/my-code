#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool vis[10001];
int dis[10001],temp[10001];
vector<pair<int,int> > rd1[10001], rd2[10001];
queue<int> q;
int dfs(int pos,int curr){
  dis[pos] = curr;
  // for (int i=0;i<rd[])
}
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++){
    int c,d,e,f; cin >> c >> d >> e >> f;
    c--;d--;
    rd1[c].push_back(make_pair(d,e));
    rd1[d].push_back(make_pair(c,e));
    rd2[c].push_back(make_pair(d,e));
    rd2[d].push_back(make_pair(c,e));
  }
  memset(dis,0x3f3f,sizeof(dis));
  dfs(0,0);

}
