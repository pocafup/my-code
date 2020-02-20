#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
vector<int> pa[1001];
pair<int,int> pos[1001];
bool visited[1001];
int dfs(int cc){
  visited[cc] = true;
  if (pa[cc].size()==0)return 0;
  int ans = 0;
  for (int i=0;i<pa[cc].size();i++){
    if (!visited[pa[cc][i]]) ans += dfs(pa[cc][i])+1;
  }
  cout << "     "<< ans << endl;
  return ans;
}
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++) {
    cin >> pos[i].first >> pos[i].second;
    pa[pos[i].first].push_back(pos[i].second);
  }
  int ans2 = 0;
  for (int i=1;i<=a;i++){
    memset(visited,0,sizeof(visited));
    visited[i] = true;
    ans2+=dfs(i);
  }
  cout << a*(a-1)/2-ans2 << endl;
}
