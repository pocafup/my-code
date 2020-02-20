#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
char grid[101][101];
#define pp pair<long long,long long>
long long a,b,c,d;

long long jumpx[4],jumpy[4];
bool vis[101][101];

bool check(pp aa,long long k){
  return aa.first+jumpx[k]>=0 && aa.first+jumpx[k]<a && aa.second+jumpy[k]<b &&aa.second+jumpy[k]>=0;
}
pp next_empty(){
  for (long long i=0;i<a;i++){
    for (long long j=0;j<b;j++){
      if (grid[i][j]=='.'&& !vis[i][j]) return make_pair(i,j);
    }
  }
}
int main(){
  cin >> a >> b >> c >> d;
  jumpx[0] = c;jumpx[1] = d;jumpx[2] = d;jumpx[3] = c;
  jumpy[0] = -d; jumpy[1] = -c;jumpy[2] = c; jumpy[3] = d;
  // jumpx[4] = {-c,-d,d,c};
  // jumpy[4] = {d,c,c,d};
  long long num = 0,ans = 0;
  for (long long i=0;i<a;i++)
    for (long long j=0;j<b;j++){
      cin >> grid[i][j];
      if (grid[i][j]=='.') num++;
    }
  while(num>0){
    for (long long i=0;i<a;i++){
      for (long long j=0;j<b;j++){
        cout << grid[i][j];
      }
      cout << endl;
    }
    cout << endl;
    pp st = next_empty();
    ans++;
    queue<pp> q;
    q.push(st);
    grid[st.first][st.second] = 'x';
    vis[st.first][st.second] = true;
    num--;
    while(!q.empty()){
      long long qf = q.front().first;
      long long qs = q.front().second;
      q.pop();
      for(long long i=0;i<4;i++){
        if (check(make_pair(qf,qs),i)){
          cout << qf+jumpx[i] << " " << qs+jumpy[i] << endl;
          if (!vis[qf+jumpx[i]][qs+jumpy[i]]&&grid[qf+jumpx[i]][qs+jumpy[i]]=='.'){
            grid[qf+jumpx[i]][qs+jumpy[i]] = 'x';
            vis[qf+jumpx[i]][qs+jumpy[i]] = true;
            q.push(make_pair(qf+jumpx[i],qs+jumpy[i]));
            num--;
          }
        }
      }
    }

  }
  cout << ans;
}
