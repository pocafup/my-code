#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define pp pair<int,int>
int n,m,pack[1005],bag[1005],ans = 0;
bool vis[1005],curr_vis[1005];
void solve(int pos){
  int keep = 0,pt = 0;
  queue<pp> q;
  while(pt<m){
    if (vis[pt]) {pt++; continue;}
    if (keep+pack[pt]<=bag[pos]) {curr_vis[pt] = true;q.push(make_pair(pack[pt],pt));keep+=pack[pt];pt++;}
    else break;
  }
  pt = 0;while(vis[pt])pt++;
  while(true){
    // cout << "keep " << keep << endl;
    if (q.empty()) break;
    if (pt==m) break;
    if (vis[pt] || curr_vis[pt]){pt++;continue;}
    // cout << "pack " << pack[pt] << " " << q.front().first << endl;
    if (keep+pack[pt]-q.front().first<=bag[pos]){
      curr_vis[pt] = true;
      curr_vis[q.front().second] = false;
      keep += pack[pt]-q.front().first;

      q.pop();
      q.push(make_pair(pack[pt],pt));
      pt++;
    }else{
      curr_vis[q.front().second] = false; vis[q.front().second] = true;q.pop(); ans++;
    }
  }
  // for (int i=0;i<m;i++) if (curr_vis[i]){cout << "curr " << pack[i] << " ";}

  // cout << endl << "qff "<< endl;
  for (int i=0;i<m;i++) if (curr_vis[i]){curr_vis[i] = false; vis[i] = true;}
  ans += q.size();

  // cout << endl;
}

int main(){
  cin >> n >> m;
  for (int i=0;i<n;i++) cin >> bag[i];
  for (int j=0;j<m;j++) cin >> pack[j];
  sort(bag,bag+n);
  sort(pack,pack+m);

  for (int i=0;i<n;i++) {
    solve(i);
    // cout << bag[i] << endl;
    // for (int j=0;j<m;j++) if (!vis[j]) cout << pack[j] << " ";
    // cout << endl;
  }
  cout << ans;
}
