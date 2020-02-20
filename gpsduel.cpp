#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define INF 2*1e8;
vector<pair<int,int> > p[10005];
vector<pair<int,int> > h[10005];
int distp[10005],disth[10005];
int ct[10005];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++){
    int c,d,e,f; cin >> c >> d >> e >> f;
    c--;d--;
    p[c].push_back(make_pair(d,e));
    p[d].push_back(make_pair(c,e));
    h[c].push_back(make_pair(d,f));
    h[d].push_back(make_pair(c,f));
  }
  // cout << endl;
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<p[i].size();j++){
  //     cout << p[i][j].first << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // queue<int> q;
  // q.push(a-1);
  // for (int i=0;i<a;i++) distp[i] = INF;
  // distp[a-1] = 0;
  // while(!q.empty()){
  //   int qt = q.front();
  //   q.pop();
  //   for (int i=0;i<p[qt].size();i++){
  //     int pf = p[qt][i].first;
  //     int ps = p[qt][i].second;
  //     if (distp[pf]>distp[qt]+ps){
  //       distp[pf] = distp[qt]+ps;
  //       q.push(pf);
  //     }
  //   }
  // }
  // for (int i=0;i<a;i++) cout << distp[i] << " ";
  // cout << endl;
  // q.push(a-1);
  // for (int i=0;i<a;i++) disth[i] = INF;
  // disth[a-1] = 0;
  // while(!q.empty()){
  //   int qt = q.front();
  //   q.pop();
  //   for (int i=0;i<h[qt].size();i++){
  //     int pf = h[qt][i].first;
  //     int ps = h[qt][i].second;
  //     if (disth[pf]>disth[qt]+ps){
  //       disth[pf] = disth[qt]+ps;
  //       q.push(pf);
  //     }
  //   }
  // }
  for (int i=0;i<a;i++) cout << disth[i] << " ";
  cout << endl;
  for (int i=0;i<a;i++) ct[i] = INF;
  q.push(0);
  ct[0] = 0;
  while(!q.empty()){
    int qf = q.front();
    q.pop();
    for (int i=0;i<p[qf].size();i++){

      int fir = p[qf][i].first;

      int ps = p[qf][i].second;
      int hs = h[qf][i].second;
      int beep = 0;

      if (distp[qf]-distp[fir]!=ps)beep++;
      if (disth[qf]-disth[fir]!=hs)beep++;

      if (ct[fir]>ct[qf]+beep){
        ct[fir] = ct[qf]+beep;
        cout << fir+1 << " " << ct[fir] << endl;
        q.push(fir);
      }
    }
  }
  for (int i=0;i<a;i++) cout << ct[i] << " ";
}
