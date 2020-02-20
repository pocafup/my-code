#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define pp pair<int,int>
char grid[51][51];
int x[4] = {1,0,-1,0};
int y[4] = {0,-1,0,1};
int island = 0;
int a,b;
int pos[51][51];
bool il[16];
bool check(pp aa, int k){
  return aa.first+x[k]>=0 && aa.first+x[k]<a&&  aa.second+y[k]>=0 && aa.second+y[k]<b;
}
int dis[51][51];
bool vis[51][51];
int spfa(pp aa){
  memset(dis,0x3f3f,sizeof(dis));
  memset(vis,0,sizeof(vis));
  dis[aa.first][aa.second] = 0;
  queue<pp> q;
  q.push(aa);
  while(!q.empty()){
    int qf = q.front().first;
    int qs = q.front().second;
    vis[qf][qs] = false;
    q.pop();
    for (int i=0;i<4;i++){
      if (check(make_pair(qf,qs),i)){
        if (grid[qf+x[i]][qs+y[i]]=='X' || grid[qf+x[i]][qs+y[i]]=='S'){
          int re = (grid[qf+x[i]][qs+y[i]]=='S') ? 1 : 0;
          if (dis[qf+x[i]][qs+y[i]]>dis[qf][qs]+re){
            dis[qf+x[i]][qs+y[i]]=dis[qf][qs]+re;
            if (!vis[qf+x[i]][qs+y[i]]){
              vis[qf+x[i]][qs+y[i]] = true;
              q.push(make_pair(qf+x[i],qs+y[i]));
            }
          }


        }
      }
    }
  }
  int maxi = 0;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      if (grid[i][j]!='X') cout << 0 << " ";
      else  cout << dis[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      if (grid[i][j]=='X') maxi = max(maxi,dis[i][j]);
    }
  }

  return maxi;
}
void mark_island(int num, pp st){
  queue<pp> q;
  q.push(st);
  vis[st.first][st.second] = true;
  while(!q.empty()){
    int qf = q.front().first;
    int qs = q.front().second;
    q.pop();
    for (int i=0;i<4;i++){
      if (check(make_pair(qf,qs),i)){
        if (grid[qf+x[i]][qs+y[i]]=='X' &&!vis[qf+x[i]][qs+y[i]]){
          pos[qf+x[i]][qs+y[i]] = num;
          vis[qf+x[i]][qs+y[i]] = true;
          q.push(make_pair(qf+x[i],qs+y[i]));
        }
      }
    }
  }
}
int main(){
  cin >> a >> b;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> grid[i][j];
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      if (grid[i][j] == 'X' && !vis[i][j]){
        pos[i][j] = ++island;
        mark_island(island,make_pair(i,j));
      }else if(grid[i][j] == 'S') {pos[i][j] = 0;
      }else if(grid[i][j] == '.') pos[i][j] = -1;
    }
  }
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<b;j++){
  //     cout << pos[i][j];
  //   }
  //   cout << endl;
  // }
  int mini = 1e8;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      if (pos[i][j]>=1){
        if (!il[pos[i][j]]){
          il[pos[i][j]] =true;
          mini = min(mini,spfa(make_pair(i,j)));
        }
      }

    }
  }
  cout << mini;
}
