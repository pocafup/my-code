#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int graph[100000];
vector<int> branch[100000];
int main(){
  int a; cin >> a;
  pair<int,int> q[a];
  for (int i=1;i<a;i++) cin >> q[i].first >> q[i].second;
  sort(q,q+a);
  //cout << endl;
  vector<int> ans;
  //for (int i=1;i<a;i++) cout << q[i].first << " " <<  q[i].second << endl;
  for (int i=1;i<a;i++){
    graph[q[i].second] += graph[q[i].first]+1;
    //cout << graph[q[i].second] << " " << q[i].second << endl;
    branch[q[i].first].push_back(q[i].second);
    if (graph[i] == i-1) {

      if (graph[i]!=0) ans.push_back(graph[i]+1);
    }
  }
  for (int i=0;i<a;i++) cout << branch[i].size() << endl;
  for (int i=0;i<ans.size();i++){
    cout << ans[i] << endl;
  }
  cout << endl;
  for (int i=0;i<ans.size();i++){
    bool n = false;
    for (int j=0;j<branch[ans[i]].size();j++){
      if(branch[branch[ans[i]][j]].size()>1){
        n = true;
      }
    }
    if (!n) cout << ans[i] << endl;
  }
  for (int i=0;i<=a;i++) cout << graph[i] << " ";
}
