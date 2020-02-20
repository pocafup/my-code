#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define INF 1e18;
long long pos[501][501];
long long way[501][501];
long long dist[501][501];
long long visited[501][501];
int main(){
  int iden = 0;
  bool zz = false;
  long long a,b; cin >> a >> b;
  long long stx,sty;
  for (long long i=0;i<a;i++)
    for (long long j=0;j<b;j++)
      cin >> pos[i][j];
  for (long long i=0;i<a;i++){
    for (long long j=0;j<b;j++){
      cin >> way[i][j];
      if (iden!=0 && way[i][j]!=iden) zz = true;
      iden = way[i][j];
      if (way[i][j]) {stx = i;sty = j;}
    }
  }

  long long ans = 0;
  long long x[4] = {0,1,0,-1};
  long long y[4] = {1,0,-1,0};
  long long right = 20000000,left = 0;

  while(left != right-1){
    long long mid = (right-left)/2+left;
    queue<pair<long long,long long> > q;
    q.push(make_pair(stx,sty));
    memset(visited,0,sizeof(visited));
    visited[stx][sty] = 1;
    while(!q.empty()){
      long long qf = q.front().first;
      long long qs = q.front().second;
      q.pop();
      for (long long i=0;i<4;i++){
        if (qf+x[i]>=0 && qs+y[i]>=0 && qf+x[i]<a&&qs+y[i]<b){
          if (!visited[qf+x[i]][qs+y[i]]&&mid>=abs(pos[qf+x[i]][qs+y[i]]-pos[qf][qs])){
            q.push(make_pair(qf+x[i],qs+y[i]));
            visited[qf+x[i]][qs+y[i]] = true;
          }
        }
      }
    }
    bool n = true;
    for (long long i=0;i<a;i++){
      for (long long j=0;j<b;j++){
        if (way[i][j] && !visited[i][j]){
          n = false;
        }
      }
    }

    if (n) right = mid;
    else left = mid;
    //cout << mid << endl;
  }

  queue<pair<long long,long long> > q;
  q.push(make_pair(stx,sty));
  memset(visited,0,sizeof(visited));
  visited[stx][sty] = 1;
  while(!q.empty()){
    long long qf = q.front().first;
    long long qs = q.front().second;
    q.pop();
    for (long long i=0;i<4;i++){
      if (qf+x[i]>=0 && qs+y[i]>=0 && qf+x[i]<a&&qs+y[i]<b){
        if (!visited[qf+x[i]][qs+y[i]]&&0>=abs(pos[qf+x[i]][qs+y[i]]-pos[qf][qs])){
          q.push(make_pair(qf+x[i],qs+y[i]));
          visited[qf+x[i]][qs+y[i]] = true;
        }
      }
    }
  }
  bool n = true;
  for (long long i=0;i<a;i++){
    for (long long j=0;j<b;j++){
      if (way[i][j] && !visited[i][j]){
        n = false;
      }
    }
  }
  if (n) ans = 0;
  zz ? cout << 0 :  cout << right;
}
