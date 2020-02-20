#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  double m; cin >> m;

  queue<pair<pair<int,int> ,int> > bfs;
  pair<int,int> re[a];
  for (int i=0;i<a;i++) cin >> re[i].first >> re[i].second;
  vector<int> q[10000];

  for (int i=0;i<b;i++){
    int c,d; cin >> c >> d;
    q[c].push_back(d);
    q[d].push_back(c);
  }
  double n[1000][1000];
  for(int i=0;i<a;i++){
    for (int j=i+1;j<a;j++){
      for (int k=0;k<q[i].size();k++){
        if (q[i][k] == j){
           n[i][j] = 0;
        }else{
          n[i][j] = sqrt(abs(re[i].first-re[j].first))+sqrt(abs(re[i].second-re[j].second));
        }
      }
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout << n[i][j] << " ";
    }
    cout << endl;
  }

  int mini = 1000000000;
  bfs.push(make_pair(make_pair(0,0),0) );

  while(!bfs.empty()){
    // int x = bfs.front().first.first;
    // int y = bfs.front().first.second;
    for (int i=bfs.front().first.first;i<a;i++){
      for (int j=bfs.front().first.second;j<a;j++){
        bfs.push(make_pair(make_pair(i,j),bfs.front().second+n[i][j]));
      }
      if (bfs.front().first.first == a-1) mini = min(mini,bfs.front().second);
    }
    bfs.pop();
  }
  cout << mini;
}
