#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

long long pos[100001];
long long dp[100001];
long long ct[100001];
long long visited[100001];
long long vis[100001];
long long prefix[100001];
vector<pair<long long,long long> > dist[100001];
int dfs(int aa){
  if (dist[aa].size()==1 && vis[dist[aa][0].first]==true) {vis[aa]=true;prefix[aa] = pos[aa]; return pos[aa];}
  for (int i=0;i<dist[aa].size();i++){
    prefix[aa]+=dfs(dist[aa][i].first);
    vis[dist[aa][i].first] = true;
  }
  return prefix[aa];
}
int main(){
  long long a; cin >> a;
  for (long long i=0;i<a;i++) cin >> pos[i];
  for (long long i=0;i<a-1;i++){
    long long c,d,e;cin >> c>>d >> e;
    dist[c-1].push_back(make_pair(d-1,e));
    dist[d-1].push_back(make_pair(c-1,e));
  }
  stack<pair<long long,long long> > st;
  visited[0] = true;
  long long ans = 1e18;
  long long temp = 0;
  st.push(make_pair(0,0));
  visited[0] = true;
  while(!st.empty()){

    long long sf = st.top().first;
    long long ss = st.top().second;
    prefix[sf] = pos[sf];
    // cout << sf << " " << ss << endl;
    if (dist[sf].size()==0){temp += ss*pos[sf];st.pop();continue;}
    else{
      bool n = true;
      for (long long i=0;i<dist[sf].size();i++){
        if (!visited[dist[sf][i].first]){
          visited[dist[sf][i].first] = true;
          st.push(make_pair(dist[sf][i].first,ss+dist[sf][i].second));
          n = false;
        }
      }
      if (n){temp += ss*pos[sf];st.pop();}
    }
  }
  ct[0] = temp;
  vis[0] = 1;
  ans = min(temp,ans);
  queue<pair<long long,long long> > q;
  queue<int> qq;
  q.push(make_pair(0,pos[0]));
  // for (int i=0;i<a;i++) prefix[0] += pos[i];
  // qq.push(0);
  // vis[0] = true;
  // while(!qq.empty()){
  //   int qf = qq.front();
  //   qq.pop();
  //   for (int i=0;i<dist[qf].size();i++){
  //     if(!vis[dist[qf][i].first]){
  //       vis[dist[qf][i].first] = true;
  //       qq.push(dist[qf][i].first);
  //       prefix[dist[qf][i].first] = prefix[qf]-pos[qf]-pos[dist[qf][i].first];
  //     }
  //   }
  // }
  vis[0] = true;
  dfs(0);
  for (int i=0;i<a;i++)cout << prefix[i] << endl;
  memset(vis,0,sizeof(vis));
  while(!q.empty()){
    int qf = q.front().first;
    int go = q.front().second;
    q.pop();
    for (int i=0;i<dist[qf].size();i++){
      int going = dist[qf][i].first;
      int weight = dist[qf][i].second;
      if (!vis[going]){
        vis[going] = true;
        q.push(make_pair(going,go+pos[going]));
        int temp2 = ct[qf];
        ct[going] = temp2-going*weight+(prefix[0]-going)*weight;
        cout << ct[going] << endl;
        ans = min(ct[going],ans);
      }
    }
  }
  cout << ans;

}
