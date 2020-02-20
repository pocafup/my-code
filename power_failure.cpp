#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
#define INF 2*1e18;
long long a,b;
double c;
double distance(pair<double,double> aa, pair<double,double> bb){
  return sqrt((aa.first-bb.first)*(aa.first-bb.first)+(aa.second-bb.second)*(aa.second-bb.second));
}
pair<double,double> pos[1001];
double dist[1001];
bool go[1001][1001];
int main(){
  cin >> a >> b >> c;
  for(int i=0;i<a;i++) cin >> pos[i].first >> pos[i].second;
  for (int i=0;i<1001;i++) dist[i] = INF;
  for (int i=0;i<b;i++){
    int d,e; cin >> d >> e;
    d--;e--;
    go[d][e] = true;
    go[e][d] = true;
    //cout << d << " " << e << endl;
  }

  queue<pair<long long,double> > q;
  dist[0] = 0;
  q.push(make_pair(0,0));
  while(!q.empty()){
    //for (int i=0;i<a;i++) cout << dist[i] << " ";
    //cout << endl;
    long long qt = q.front().first;
    q.pop();
    for (int i=0;i<a;i++){
      if (go[qt][i]){
        if (dist[i]>dist[qt]){
          dist[i] = dist[qt];
          q.push(make_pair(i,dist[i]));
          //cout << dist[i] << " " << i << endl;
        }
      }else{
        if (distance(pos[qt],pos[i])<=c){
          if (dist[i]>dist[qt]+distance(pos[qt],pos[i])){
            dist[i] = dist[qt]+distance(pos[qt],pos[i]);
            q.push(make_pair(i,dist[i]));
          }
        }

      }

    }


  }
  dist[a-1] *= 1000;
//   cout << -1;
  (long long)dist[a-1] >= 2*1e8 ? cout << -1 : cout << (int)dist[a-1];
}
