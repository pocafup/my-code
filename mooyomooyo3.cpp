#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
#define pp pair<int,int>
int n,k;
bool vis[101][101];
int grid[101][101];
int x[4] = {-1,0,0,1};
int y[4] = {0,1,-1,0};
bool check(int a, int b, int k){
  return a+x[k]<n && a+x[k]>=0 && b+y[k]<10 && b+y[k]>=0;
}
bool update;
void compute(pp pos,int curr){
  vis[pos.first][pos.second] = true;
  queue<pp> q,q2;q.push(pos);q2.push(pos);
  while(!q.empty()){
    int qf = q.front().first;
    int qs = q.front().second;
    q.pop();
    for (int k=0;k<4;k++){
      if (check(qf,qs,k)){
        if (!vis[qf+x[k]][qs+y[k]]&&grid[qf+x[k]][qs+y[k]]==curr){
          vis[qf+x[k]][qs+y[k]] = true;
          q.push(make_pair(qf+x[k],qs+y[k]));
          q2.push(make_pair(qf+x[k],qs+y[k]));
        }
      }
    }
  }
  if (q2.size()>=k){
    while(!q2.empty()){
      grid[q2.front().first][q2.front().second] = 0;
      q2.pop();
    }
    update = true;
  }
}
void drop(){
  for (int i=0;i<10;i++){
    int bot = n-1, top;
    while(grid[bot][i]!=0){bot--;if (bot<0)break;}
    top = bot;
    while(top!=0&&bot!=0){
      while(grid[top][i]==0){top--;if (top<0)break;}
      if(top<0)break;
      swap(grid[top][i],grid[bot][i]);
      while(grid[bot][i]!=0){bot--;if (bot<0)break;}
    }
  }
}
int main(){
  // ifstream cin ("mooyomooyo.in");
  // ofstream cout("mooyomooyo.out");
  cin >> n >> k;
  cin.ignore();
  for (int i=0;i<n;i++){
    string s;
    getline(cin,s);
    for (int j=0;j<10;j++){
      grid[i][j] = (int)s[j]-48;
    }
  }
  update = true;
  while(update){
    update = false;
    memset(vis,0,sizeof(vis));
    for (int i=0;i<n;i++){
      for (int j=0;j<10;j++){
        if (!vis[i][j]&&grid[i][j]!=0) {
          compute(make_pair(i,j),grid[i][j]);
        }
      }
    }
    drop();
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<10;j++){
      cout << grid[i][j];
    }
    cout << endl;
  }
}
