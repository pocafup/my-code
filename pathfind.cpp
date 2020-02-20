#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int main(){
  queue<pair<int,int> > cc;
  int a,b;
  cin >> a >> b;
  queue<pair<int,int> > q;
  int c[a+3][a+3];
  int visited[a+3];
  memset(c,0,sizeof(c));
  memset(visited,0,sizeof(visited));
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cin >> c[i][j];
    }
  }
  pair<int,int> res;
  res.first = b-1;
  res.second = 0;
  q.push(res);
  pair<int,int> res2;
  res2.first = b;
  res2.second = 0;
  cc.push(res2);
  visited[b-1] = true;
  while (!q.empty()){
    for (int i=0;i<a;i++){
      if (!visited[i] && c[q.front().first][i] == 1){
        visited[i] = true;
        pair<int,int> re;
        re.first = i;
        re.second = q.front().second+1;
        pair<int,int> re2;
        re2.first = i+1;
        re2.second = q.front().second+1;
        cc.push(re2);
        q.push(re);
      }
    }
    q.pop();
  }
  while(!cc.empty()){
    b = cc.front().second;
    vector<int> si;
    while (b == cc.front().second){
      si.push_back(cc.front().first);
      cc.pop();
    }
    sort(si.begin(),si.end());
    while(!si.empty()){
      cout << si[0] << " ";
      si.erase(si.begin());
    }
    cout << endl;
  }
}
