#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int d,e; char f;
int pos[201][201];
int vis[201][201];
int main(){
  int a,b,c;
  int maxx = 0;
  int maxy = 0;
  for(int i=0;i<a;i++){
    cin >> d >> e >> f;
    if (f == '/') pos[d][e] = 2;
    else pos[d][e] = 3;
    maxx = max(maxx,d);
    maxy = max(maxy,e);
  }
  queue<pair<pair<int,int> > > q;
  q.push(make_pair(make_pair(0,0),-1));
  x[4] = {0,1,0,-1};
  y[4] = {1,0,-1,0};
  vis[0][0] = true;
  while(!q.empty()){
    qx = q.front().first.first;
    qy = q.front().first.second;
    vi = q.front().second;
    q.pop();
    if (pos[qx][qy] == 0){
      for (int i=0;i<4;i++){
        if (qx+x[i]<=maxx&&qy+y[i]<=maxy && qx+x[i]>=0 && qy+y[i]>=0){
          if (!vis[qx+x[i]][qy+y[i]]){
            vis[qx+x[i]][qy+y[i]] = true;
            q.push(make_pair(make_pair(qx+x[i],qy+y[i]),vi));
          }
        }
      }
    }
    if (pos[qx][qy] == 2){
      
    }
  }
}
