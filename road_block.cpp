#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define INF 2*1e8;
vector<pair<int,int> > go[25005];
int c,d,e,ans=0;
int dist[255];
pair<pair<int,int>,int > pos[25005];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++){
    cin >> c >> d >> e;
    c--;d--;
    go[c].push_back(make_pair(d,e));
    go[d].push_back(make_pair(c,e));
    pos[i] = make_pair(make_pair(c,d),e);
  }
  for (int i=0;i<a;i++) dist[i] = INF;
  dist[0] = 0;
  queue<pair<int,int> > dik;
  dik.push(make_pair(0,0));
  while(!dik.empty()){
    int qf = dik.front().first;
    int qs = dik.front().second;
    dik.pop();
    for (int i=0;i<go[qf].size();i++){
      int going = go[qf][i].first;
      int route2 = go[qf][i].second;
      if (qs+route2<dist[going]){
        dist[going] = qs+route2;
        dik.push(make_pair(going,qs+route2));
      }

    }
  }
  int ans2 = dist[a-1];
  for (int i=0;i<b;i++){
    int maxi = max(pos[i].first.first,pos[i].first.second);
    int mini = min(pos[i].first.first,pos[i].first.second);
    int route = pos[i].second*2;
    for (int i=0;i<a;i++) dist[i] = INF;
    dist[0] = 0;
    dik.push(make_pair(0,0));
    while(!dik.empty()){
      int qf = dik.front().first;
      int qs = dik.front().second;
      dik.pop();
      for (int i=0;i<go[qf].size();i++){
        int going = go[qf][i].first;
        int route2 = go[qf][i].second;
        int sad1 = max(qf,going);
        int sad2 = min(qf,going);
        if (sad1!=maxi || sad2!=mini){
          if (qs+route2<dist[going]){
            dist[going] = qs+route2;
            dik.push(make_pair(going,qs+route2));
          }
        }else{
          if (qs+route<dist[going]){
            dist[going] = qs+route;
            dik.push(make_pair(going,qs+route));
          }
        }
      }
    }
    ans = max(ans,dist[a-1]);
  }
  cout << ans-ans2;
}
