#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e18;
long long pos[501][501];
long long waypolong long[501][501];
long long dist[501][501];
int main(){
  long long a,b; cin >> a >> b;
  for (long long i=0;i<a;i++)
    for (long long j=0;j<b;j++)
      cin >> pos[i][j];
  vector<pair<long long,long long> > wap;
  for (long long i=0;i<a;i++){
    for (long long j=0;j<b;j++){
      cin >> waypolong long[i][j];
      if (waypolong long[i][j]){
        wap.push_back(make_pair(i,j));
      }
    }
  }
  long long ans = 0;
  long long x[4] = {0,1,0,-1};
  long long y[4] = {1,0,-1,0};
  while(wap.size()>1){
    for (long long i=0;i<a;i++){
      for (long long j=0;j<b;j++){
        dist[i][j] = INF;
      }
    }
    dist[wap[0].first][wap[0].second] = 0;
    long long local = 0;
    queue<pair<long long,long long> > q;
    q.push(make_pair(wap[0].first,wap[0].second));
    while(!q.empty()){
      long long qt = q.front().first;
      long long qs = q.front().second;
      q.pop();
      for (long long i=0;i<4;i++){
        if (qt+x[i]>=0 && qs+y[i]>=0 && qt+x[i]<a&&qs+y[i]<b){
          if (dist[qt+x[i]][qs+y[i]]>abs(pos[qt+x[i]][qs+y[i]]-pos[qt][qs])){
            dist[qt+x[i]][qs+y[i]] = abs(pos[qt+x[i]][qs+y[i]]-pos[qt][qs]);
            q.push(make_pair(qt+x[i],qs+y[i]));
          }
        }
      }
    }
    for (long long i=1;i<wap.size();i++){
      ans = max(dist[wap[i].first][wap[i].second],ans);
    }
    wap.erase(wap.begin());
  }
  cout << ans;
}
