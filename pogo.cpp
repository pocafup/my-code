#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int,int> pos[40005];
int bsdist[40005];
int esdist[40005];
int togo[40005];
vector<int> vec[40005];
int main(){
  int a,b,c,d,e; cin >> a >> b >> c >>d >> e;
  for (int i=0;i<e;i++){
    cin >> pos[i].first >> pos[i].second;
    vec[pos[i].first].push_back(pos[i].second);
    vec[pos[i].second].push_back(pos[i].first);
  }
  priority_queue<pair<int,int> > q;
  int begin = 0;
  for (int i=0;i<vec[1].size();i++){
    q.push(make_pair(a,vec[1][i]));
  }
  for (int i=0;i<=d;i++) bsdist[i] = 200000000;
  while(!q.empty()){

    int qs = q.top().second;
    int qf = q.top().first;
    //cout << qf << " " << qs << endl;
    q.pop();
    if (bsdist[qs]>qf){
      bsdist[qs] =qf;
      for(int i=0;i<vec[qs].size();i++){
        q.push(make_pair(qf+a,vec[qs][i]));
      }
    }
  }
  // for (int i=0;i<=d;i++){
  //    cout << bsdist[i] << " ";
  // }
  for (int i=0;i<vec[2].size();i++){
    q.push(make_pair(b,vec[2][i]));
  }
  //cout << endl;
  for (int i=0;i<=d;i++) esdist[i] = 200000000;
  while(!q.empty()){
    int qs = q.top().second;
    int qf = q.top().first;
    //cout << qf << " " << qs << endl;
    q.pop();
    if (esdist[qs]>qf){
      esdist[qs] = qf;
      for(int i=0;i<vec[qs].size();i++){
        q.push(make_pair(qf+b,vec[qs][i]));
      }
    }
  }
  int re = 0;
  for (int i=0;i<=d;i++){
    if (bsdist[i]!=200000000 && esdist[i]!=200000000){
      re = i;
      break;
    }
  }
  int ans = esdist[d]+bsdist[d];
  int mini = 200000;
  int re = 0;
  for (int i=0;i<a;i++){
    if (esdist[i]!=200000000 && bsdist[i]!=200000000 && esdist[i]+bsdist[i]<mini){
      re = i;
      mini = esdist[i]+bsdist[i];
    }
  }
  int xx = 0;
  for (int i=0;i<=d;i++) togo[i] = 200000000;
  for (int i=0;i<vec[re].size();i++){
    q.push(make_pair(c,vec[re][i]));
  }
  while(!q.empty()){
    int qs = q.top().second;
    int qf = q.top().first;
    q.pop();
    if (esdist[qs]>qf){
      togo[qs] = qf;
      for(int i=0;i<vec[qs].size();i++){
        q.push(make_pair(qf+c,vec[qs][i]));
      }
    }
  }
  ans = min(ans,esdist[re]+bsdist[re]+togo[d]);

  cout << ans << endl;
  // cout << endl << re << endl;
  // cout << min(esdist[d] + bsdist[d], esdist[re]+bsdist[re]+togo[d]);
}
