#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int fat[100001],level[100001];
int barn[100001];
vector<int> vec[100001];
int main(){
  ifstream cin ("milkvisits.in");
  ofstream cout ("milkvisits.out");
  cin >> n >>m;
  for (int i=1;i<=n;i++) {char d;cin >> d; barn[i] = (d=='G') ? 1 : 2;}
  for (int i=1;i<=n;i++) fat[i] = i;
  for (int i=0;i<n-1;i++){
    int a,b;cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  bool vis[n+1];
  for (int i=0;i<m;i++){
    memset(vis,0,sizeof(vis));
    int c,d; char e; cin >> c >> d >> e;
    int re = (e=='G') ? 1:2;
    if (barn[c]!=barn[d]) {cout << 1; continue;}
    queue<pair<int,int> > q;
    q.push(make_pair(c,barn[c]));
    vis[c] = true;
    while(!q.empty()){
      int qf = q.front().first, qs = q.front().second;q.pop();
      // cout << "qf "<<  qf << endl;
      if (qf==d) {cout << ((qs==3) || qs==re); break;}
      for (int i=0;i<vec[qf].size();i++){
        if (!vis[vec[qf][i]]){
          vis[vec[qf][i]] = true;
          int re = (qs==barn[vec[qf][i]]) ? qs : 3;
          q.push(make_pair(vec[qf][i],re));
        }
      }
    }
  }

}
