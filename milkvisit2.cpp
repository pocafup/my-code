#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#define pp pair<int,int>
vector<pp> vec[500005];
int n,m;
bool vis[100005];
int barn[500005];
void dfs(int pos){
  for (int i=0;i<vec[pos].size();i++) {
    dfs(vec[pos][i].first);
    for (int j=0;j<vec[vec[pos][i].first].size();j++){
      if (barn[pos]!=vec[vec[pos][i].first][j].second){
        vec[pos].push_back(make_pair(vec[vec[pos][i].first][j].first,3));
      }else{
        vec[pos].push_back(vec[vec[pos][i].first][j]);
      }
    }
  }
}
int main(){
  ifstream cin ("milkvisits.in");
  ofstream cout ("milkvisits.out");
  cin >> n >>m;

  for (int i=1;i<=n;i++) {char dd; cin >> dd; if (dd=='G')barn[i] = 1;else barn[i] = 2;}
  for (int i=0;i<n-1;i++){
    int a,b;cin >> a >> b;
    if (a>b) swap(a,b);
    vec[a].push_back(make_pair(b,barn[b]));
    vec[b].push_back(make_pair(a,barn[a]));
  }
  for (int i=1;i<=n;i++){
    dfs(i);
  }
  // for (int i=1;i<=n;i++){
  //   for (int j=0;j<vec[i].size();j++){
  //     cout << vec[i][j].first << " " << vec[i][j].second << endl;
  //   }
  //   cout << endl << endl;
  // }
  for (int i=0;i<m;i++){
    int c,d;char e; cin >> c >> d >> e;
    int re = (e=='G') ? 1 : 2;
    if (c>d) swap(c,d);
    if (barn[c]==re || barn[d]==re){cout <<1; continue;}
    if (c==d) {cout << (barn[c]==re); continue;}
    for(int i=0;i<vec[c].size();i++){
      if (vec[c][i].first==d){
        if (vec[c][i].second == 3 || vec[c][i].second==re) cout<<1;
        else cout << 0;
        break;
      }
    }
  }
}
