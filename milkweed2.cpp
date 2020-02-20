#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool pos[101][101];

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  c--; d = b-d;
  for (int i=0;i<b;i++){
    for (int j=0;j<a;j++){
      char e; cin >> e;
      pos[i][j] = e =='.' ? 0 : 1;
    }
  }
  pos[d][c] = true;

  for (int i=0;i<b;i++){
    for (int j=0;j<a;j++){
      cout << pos[i][j] << " ";
    }
    cout << endl;
  }
  queue<pair<pair<int,int>,int> > q;
  q.push(make_pair(make_pair(d,c),0));
  int x[8] = {0,1,1,1,0,-1,-1,-1};
  int y[8] = {1,1,0,-1,-1,-1,0,1};
  int ans = 0;
  while(!q.empty()){
    int qf = q.front().first.first;
    int qs = q.front().first.second;
    int times = q.front().second;
    ans = max(ans,times);
    q.pop();
    for (int i=0;i<8;i++){
      if (qf+x[i]>=0 && qs+y[i]>=0 && qf+x[i]<b && qs+y[i]<a){
        if (!pos[qf+x[i]][qs+y[i]]){
          pos[qf+x[i]][qs+y[i]] = true;
          q.push(make_pair(make_pair(qf+x[i],qs+y[i]),times+1));
        }
      }
    }
  }
  for (int i=0;i<b;i++){
    for (int j=0;j<a;j++){
      cout << pos[i][j] << " ";
    }
    cout << endl;
  }
  cout << ans;
}
