#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <fstream>

using namespace std;
int n,m,ans = 0;
map<string,int> mp;
int pref[100005][31];
int main(){
  // ifstream cin ("desktop/abcac.in");
  cin >> n >> m;
  // cout << n;
  for (int i=1;i<=n;i++){
    int a; cin >> a;
    int mini = 1e8;
    for (int j=0;j<m;j++){
      pref[i][j] = pref[i-1][j];
      if ((a>>j)&1)pref[i][j]++;
      mini = min(mini,pref[i][j]);
    }
    if (mini)for (int j=0;j<m;j++) pref[i][j]--;
  }

  for (int i=0;i<=n;i++){
    string s;
    for (int j=0;j<m;j++)s+=pref[i][j]+65;
    map<string,int>::iterator it;
    it = mp.find(s);
    if (it!=mp.end()) ans = max(ans,i-mp[s]);
    else mp[s] = i;
  }
  cout << ans;
}
