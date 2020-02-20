#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
#define INF 200000000;

vector<int> path[2000];
vector<pair<int,int> > cost_past[3000];
int dist[2000];
int main(){
  int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
  e--;
  for (int i=0;i<b;i++){
    int f,g; cin >> f >> g;
    f--;g--;
    path[f].push_back(g);
  }
  for (int i=0;i<d;i++){
    int aa,ab,ac; cin >> aa >> ab >> ac;
    aa--;ab--;
    cost_past[aa].push_back(make_pair(ab,ac));
  }
  for (int i=0;i<c;i++) dist[i] = 0;
  dist[e] = a;
  bool update = true;
  while(update){
    // for (int i=0;i<c;i++) cout << dist[i] << endl;
    // cout << endl;
    update = false;
    for (int i=0;i<c;i++){
      for (int j=0;j<path[i].size();j++){
        if(dist[path[i][j]]<dist[i]+a){

          dist[path[i][j]] = dist[i]+a;
          update = true;
        }
        if (dist[path[i][j]] == 0) dist[path[i][j]] = dist[i]+a;
      }
    }
    for (int i=0;i<c;i++){
      for (int j=0;j<cost_past[i].size();j++){

        if(dist[cost_past[i][j].first]<dist[i]+a-cost_past[i][j].second){
          dist[cost_past[i][j].first] = dist[i]+a-cost_past[i][j].second;
          update = true;
        }
        // if (dist[cost_past[i][j].first] == 0) dist[cost_past[i][j].first] = dist[i]+a-cost_past[i][j].second;
      }
    }

  }
  // cout << endl;
  // for (int i=0;i<c;i++){
  //   cout << i << " ";
  //   for (int j=0;j<path[i].size();j++){
  //     cout << path[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // for (int i=0;i<c;i++) cout << dist[i] << endl;
  int maxi = 0;
  for (int i=0;i<c;i++) maxi = max(maxi,dist[i]);
  cout << maxi;
}
