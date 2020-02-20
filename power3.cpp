#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <limits.h>
#include <queue>


using namespace std;

int dist[1000];
bool prev[1000];
int main(){

  int a,b; cin >> a >> b;
  double c; cin >> c;
  priority_queue<pair<pair<int,int>, int> > q;
  pair<int,int> verx[a];
  for (int i=0;i<a;i++){
    cin >> verx[i].first >> verx[i].second;
  }
  vector<int> vec[b];
  for (int i=0;i<b;i++){
    int c,d; cin >> c >> d;
    vec[c].push_back(d);
    vec[d].push_back(c);
  }
  dist[0] = 0;
  for (int i=1;i<a;i++){
    dist[i] = INT_MAX, prev[i] = false;
    q.push(make_pair(verx[i],dist[i]));
  }
  while(!q.empty()){
    int u = q.extract_min();
    for (int i=0;i<a;i++){
      
    }
  }
}
