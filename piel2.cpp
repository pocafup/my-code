#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int c[a][b];
  int x[2] = {0,-1};
  int y[2] = {-1,-1};
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> c[i][j];
    }
  }
  int visited[a][b];
  memset(visited,0,sizeof(visited));
  queue<pair<int,pair<int,int> > > q;
  pair<int,pair<int,int> > s;
  s.first = c[a-1][b-1];
  s.second.first = a-1;
  s.second.second = b-1;
  int maxi = 0;
  q.push(s);
  visited[a-1][b-1] = 1;
  while (!q.empty()){
    for (int i=0;i<2;i++){
      if (q.front().second.first+x[i]>=0 && q.front().second.second+y[i]>=0){
        if (visited[q.front().second.first+x[i]][q.front().second.second+y[i]]==0){
          visited[q.front().second.first+x[i]][q.front().second.second+y[i]] = true;
          pair<int,pair<int,int> > s1;
          s1.first = c[q.front().second.first][q.front().second.second]+c[q.front().second.first+x[i]][q.front().second.second+y[i]];
          c[q.front().second.first+x[i]][q.front().second.second+y[i]] += c[q.front().second.first][q.front().second.second];
          s1.second.first = q.front().second.first+x[i];
          s1.second.second = q.front().second.second+y[i];
          q.push(s1);
        }
      }
    }
    if (q.front().second.first == 0 && q.front().second.second == 0){
      maxi = max(maxi,c[0][0]);
    }
    q.pop();
  }
  for (int i=0;i<a;i++){

    for (int j=0;j<b;j++){
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
  cout << maxi;
}
