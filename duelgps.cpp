#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define INF -2*1e8;
vector<pair<int,int> > p[10005];
vector<pair<int,int> > h[10005];
int distp[10005],disth[10005];
int ct[10005];
int visited[100000];
int distpo[10005];
int distho[10005];
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
  cout << endl;
  queue<int> q;
  queue<pair<int,int> > qq;
  for (int i=0;i<a;i++) distpo[i] = INF;
  distpo[a-1] = 0;
  cout << endl;
  qq.push(make_pair(a-1,0));
  while(!qq.empty()){
    int qt = qq.front().first;
    int qs = qq.front().second;
    //cout << qt << endl;
    qq.pop();
    for (int i=0;i<p[qt].size();i++){
      int pf = p[qt][i].first;
      int ps = p[qt][i].second;
      if (distpo[pf]<distpo[qt]-ps){
        distpo[pf] = distpo[qt]-ps;
        qq.push(make_pair(pf,distpo[pf]));
      }
    }
  }
  for (int i=0;i<a;i++) cout << distpo[i] << " ";
  cout << endl;
  for (int i=0;i<a;i++) distho[i] = INF;
  distho[a-1] = 0;
  qq.push(make_pair(a-1,0));
  while(!qq.empty()){
    int qt = qq.front().first;
    int qs = qq.front().second;
    //cout << qt << endl;
    qq.pop();
    for (int i=0;i<h[qt].size();i++){
      int pf = h[qt][i].first;
      int ps = h[qt][i].second;
      if (distho[pf]<distho[qt]-ps){
        distho[pf] = distho[qt]-ps;
        qq.push(make_pair(pf,distho[pf]));
      }
    }
  }

  for (int i=0;i<a;i++) cout << distho[i] << " ";
  cout << endl;
  for (int i=0;i<a;i++) ct[i] = -INF;
  ct[0] = 0;
  q.push(0);
  while(!q.empty()){
    int qf = q.front();
    q.pop();
    //cout << p[qf].size() << endl;
    for (int i=0;i<p[qf].size();i++){
      int fir = p[qf][i].first;
      int ps = p[qf][i].second;
      int hs = h[qf][i].second;
      int beep = 0;
      int da = -distpo[fir];
      int df = -distpo[qf];
      int ha = -distho[fir];
      int hf = -distho[qf];
      //cout << "       " << -distp[a-1] << " " << -distp[fir] << " " << ps << endl;
      if (da+ps!=df)beep++;
      if (ha+hs!=hf)beep++;
      cout << da << " " << ps << " " << df << endl;
      cout << ha << " " << hs << " " << hf << endl;
      cout << beep << endl;
      if (ct[fir]>ct[qf]+beep && fir>qf){
        ct[fir] = ct[qf]+beep;
        cout  << ct[fir] << " " << fir << endl;

        q.push(fir);
      }
    }
  }
  for (int i=0;i<a;i++) cout << ct[i] << " ";
  cout << ct[a-1];
}
