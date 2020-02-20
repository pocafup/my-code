#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

int c,d;
bool vis[10001];
vector<int> pos[10001];
vector<int> pos2[10001];
stack<int> st;
void dfs(int aa){
  for (int i=0;i<pos[aa].size();i++){
    if (!vis[pos[aa][i]]){
      vis[pos[aa][i]] = true;
      st.push(pos[aa][i]);
      dfs(pos[aa][i]);
    }
  }
}
int dfs2(int aa,int start,int num){
  for (int i=0;i<pos2[aa].size();i++){
    if (!vis[pos2[aa][i]]){
      vis[pos2[aa][i]] = true;
      num = dfs2(pos2[aa][i],start,num);
    }
  }
  if (aa == start) num++;
  return num;
}
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++){
    cin >> c >> d;
    c--;d--;
    pos[c].push_back(d);
    pos2[d].push_back(c);
  }
  for (int i=0;i<a;i++){
    if (!vis[i]){
      vis[i] = true;
      st.push(i);
      dfs(i);
    }
  }
  memset(vis,0,sizeof(vis));
  int ans = 0;
  while(!st.empty()){
    if (!vis[st.top()]){
      if (dfs2(st.top(),st.top(),0)>1) ans++;
    }
    st.pop();
  }
  cout << ans;
}
