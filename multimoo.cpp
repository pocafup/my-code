/*
ID:dx424391
PROG: multimoo
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;

bool visited[251][251];
bool vis[251][251];
int grid[251][251];
int main(){
  ofstream cout("multimoo.out");
  ifstream cin("multimoo.in");
  int a; cin >> a;
  for (int i=0;i<a;i++)
    for (int j=0;j<a;j++)
      cin >> grid[i][j];
  queue<pair<int,int> > q;
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  int ans1 = 0,ans2 = 0,turn;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (!visited[i][j]){
        visited[i][j] = true;
        q.push(make_pair(i,j));
        turn = 0;
        while(!q.empty()){
          turn++;
          int qf = q.front().first;
          int qs = q.front().second;
          //cout << qf << " " << qs << " " << turn << endl;
          q.pop();
          for (int k=0;k<4;k++){
            if (qf+x[k]>=0 && qf+x[k]<a && qs+y[k]>=0 && qs+y[k]<a){
              if (!visited[qf+x[k]][qs+y[k]] && grid[qf+x[k]][qs+y[k]] == grid[qf][qs]){
                q.push(make_pair(qf+x[k],qs+y[k]));
                visited[qf+x[k]][qs+y[k]] = true;
              }
            }
          }
        }
        ans1 = max(ans1,turn);
      }
    }
  }
  ans2 = 0;
  bool n = false;
  for (int i=0;i<a;i++){
    if(n) break;
    for (int j=0;j<a;j++){
      if (n) break;
      vis[i][j] = true;
      memset(visited,0,sizeof(visited));
      for (int k=0;k<4;k++){
        if (i+x[k]>=0 && i+x[k]<a && j+y[k]>=0 && j+y[k]<a){
          if (!visited[i+x[k]][j+y[k]] && grid[i+x[k]][j+y[k]]!=grid[i][j]){
            visited[i+x[k]][j+y[k]] = true;
            visited[i][j] = true;
            int b1 = grid[i+x[k]][j+y[k]];
            int b2 = grid[i][j];
            q.push(make_pair(i,j));
            q.push(make_pair(i+x[k],j+y[k]));
            turn = 0;
            while(!q.empty()){
              turn++;
              int qf = q.front().first;
              int qs = q.front().second;
              q.pop();
              for (int l=0;l<4;l++){
                if (qf+x[l]>=0 && qf+x[l]<a && qs+y[l]>=0 && qs+y[l]<a){
                  if (!visited[qf+x[l]][qs+y[l]] && (grid[qf+x[l]][qs+y[l]] == b1 || grid[qf+x[l]][qs+y[l]] == b2)){
                    visited[qf+x[l]][qs+y[l]] = true;
                    q.push(make_pair(qf+x[l],qs+y[l]));
                  }
                }
              }
            }
            ans2 = max(ans2,turn);
            if (ans2 == a*a){n = true; break;}
          }
        }
      }
    }
  }
  cout << ans1 << endl << ans2;
}
