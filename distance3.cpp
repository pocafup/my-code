#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
int level[100001];
int ans[100001][30];
vector<int> pa[100001];
bool visited[100001];
int dfs(int a, int b) {
        ans[a][0] = b;
        for (int i = 1; i <= 17; i++)
            ans[a][i] = ans[ans[a][i - 1]][i - 1];
        for (int j=0;j<pa[a].size();j++) {
            if (j != b) {

                level[j] = level[a] + 1;
                dfs(j,a);
            }
        }
    }
int lca(int a,int b){
  if (level[a]<level[b]) swap(a,b);
  int dist = level[a]-level[b];
  // while(dist>0){
  //   int dd = log2(dist);
  //   a = ans[a][dd];
  //   dist-= (1<<dd);
  // }
  for (int i = 17;i>=0;i--){
    if (level[a]-(1<<i)>=level[b]){
      a = ans[a][i];
    }
  }

  if (a==b) return a;
  // cout << "ee" << endl;
  for (int k=17;k>=0;k--){
    // cout << "     " << a << " " << b << endl;
    if(ans[a][k] != -1 && ans[a][k]!=ans[b][k]){
      a = ans[a][k];
      b = ans[b][k];
    }
  }

  return ans[a][0];
}
pair<int,int> N[100001];
pair<int,int> Q[100001];
vector<int> vec[100001];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a-1;i++){
    cin >> N[i].first >> N[i].second;
    vec[N[i].first].push_back(N[i].second);
    pa[N[i].second].push_back(N[i].first);
  }
  for (int i=0;i<b;i++) cin >> Q[i].first >> Q[i].second;
  // for (int i=1;i<=a;i++) cout << pa[i] << endl;
  for (int i=1;i<=a;i++){
    for (int j=0;(1<<j)<a;j++){
      ans[i][j] = -1;
    }
  }

  for (int i=1;i<=a;i++) ans[i][0] = pa[i][0];
  // for (int i=0;i<=a;i++){
  //   for (int j=0;j<a;j++){
  //     cout << ans[i][j] << " ";
  //   }
  //   cout << "   ee" <<  endl;
  // }

  for(int i = 1 ; i <= a ; i++){
    for(int j = 1; (1<<j) < a ; j++){
      if(ans[i][j-1] != -1) ans[i][j] = ans[ans[i][j-1]][j-1] ;
    }
  }
  // for (int i=0;i<=a;i++){
  //   for (int j=0;j<a;j++){
  //     cout << ans[i][j] << " ";
  //   }
  //   cout << "   ee" <<  endl;
  // }
  // cout << endl;
  int start = -1;
  queue<pair<int,int> > q;
  for (int i=1;i<a;i++){
    if (ans[i][0] == 0 ){start = i; break;}
  }
  // q.push(make_pair(start,1));
  // visited[start] = true;
  // while(!q.empty()){
  //   int qf = q.front().first;
  //   int qs = q.front().second;
  //   level[qf] = qs;
  //   q.pop();
  //   for (int i=0;i<vec[qf].size();i++){
  //     if (!visited[vec[qf][i]]) q.push(make_pair(vec[qf][i],qs+1));
  //   }
  // }
  dfs(0,0);
  // for (int i=0;i<=a;i++) cout << i << " " << level[i] << endl;
  // cout << endl;
  cout << lca(6,7) << " " << lca(8,9) << " " << lca(3,7)<< " " << lca(2,4) << " " << lca(13,10) << " " << lca(7,2) << endl;
  // cout << lca(2,3) << " " << lca(1,3) << " " << lca(1,4) << " " << lca(4,5) << " " << lca(6,7) << " " << lca(6,3) << endl;
  for (int i=0;i<b;i++){
    // cout << level[Q[i].first] << " " << level[Q[i].second] << " " << level[lca(Q[i].first,Q[i].second)] << endl;
    // cout << lca(Q[i].first,Q[i].second) << endl;

    cout << level[Q[i].first]+level[Q[i].second]-2*level
                [lca(Q[i].first,Q[i].second)] << endl;
  }

}
