#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp_left[40001],dp_right[40001],lef[40001],ri[40001];

pair<int,int> arr
int main(){
  int a,b,c; cin >> a >> b>> c;
  for (int i=0;i<a;i++) {cin >> lef[i]; dp_left[i] = lef[i];}
  for (int i=0;i<b;i++) {cin >> ri[i];dp_right[i] = ri[i];}
  for (int i=0;i<c;i++){
    int d,e; cin >> d >> e;
    d--;e--;
    if (e<=d)vec_left[d].push_back(e);
    if (d<=e) vec_right[e].push_back(d);
  }
  int prev,prev1;
  for (int i=0;i<a;i++) sort(vec_left[i].begin(),vec_left[i].end());
  for (int i=0;i<b;i++) sort(vec_right[i].begin(),vec_right[i].end());
  int ans = 0;
  for (int i=0;i<max(a,b);i++){
    prev = 0;prev1 = 0;
    bool update = false;
    if (i<a) prev1 = dp_left[i];
    if (i<b) prev = dp_right[i];

      for (int j=0;j<vec_left[i].size();j++){
        // cout << vec_left[i][j] << " " << i << " " << j << endl;
        if (vec_left[i][j]<i) dp_left[i] = max(dp_left[i],prev1+dp_right[vec_left[i][j]]);
        if (vec_left[i][j]==i) update = true;
      }


      for (int j=0;j<vec_right[i].size();j++){
        if (vec_right[i][j]<i) dp_right[i] = max(dp_right[i],prev+dp_left[vec_right[i][j]]);
      }

    prev1 = dp_left[i];
    if (update) {
      dp_left[i] = max(dp_left[i],dp_right[i]+lef[i]);
      dp_right[i] = max(dp_right[i],prev1+ri[i]);
    }

  }
  for (int i=0;i<a;i++) ans = max(ans,dp_left[i]);
  // for (int i=0;i<a;i++) cout << dp_left[i] << " " ;
  // cout << endl;
  // for (int i=0;i<b;i++) cout << dp_right[i] << " " ;
  // cout << endl;
  for (int i=0;i<b;i++) ans = max(ans,dp_right[i]);
  cout << ans;
}
