#include <iostream>
#include <algorithm>

using namespace std;
int dp[(1<<16)+1];
int prefix[100001];
int money[18],cost[100001];
int main(){
  int a,b; cin >> a >> b;
  for (int i=1;i<=a;i++) cin >> money[i];
  for (int i=1;i<=b;i++) {cin >> cost[i];prefix[i] = prefix[i-1]+cost[i];}
  dp[0] = 0;
  for (int i=1;i<=(1<<a);i++){
    for (int j=0;(1<<j)<(1<<a);j++){
      int cc = i%(1<<j);
      // cout << "       i = " << i << " " << (1<<(j+1)) << " " << cc << " " << (1<<j) << endl;
      if ((cc<=(1<<j) && i>=(1<<j)) || (i==(1<<j))){
        // cout << " cc = " << cc <<  " i = " << i << endl;
        if (dp[i-(1<<j)]==b) continue;
        int left = dp[i-(1<<j)];
        if (i==(1<<j)) left = 0;
        int right = b;
        // cout << left << " " << right << " " << j << " " << money[j+1] << endl;
        while(left<right-1){
          int mid = (left+right)/2;
          if (prefix[mid]-dp[i-(1<<j)]>money[j+1]) right = mid;
          else left = mid;
        }
        // cout << "left = " << left << " right = " << right << endl;
        // int keep = 0;
        // cout << prefix[right] << " " << prefix[dp[i-(1<<j)]] << " " << money[j+1]<< endl;
        if (prefix[right]-prefix[dp[i-(1<<j)]]<=money[j+1]) dp[i] = max(dp[i],right);
        else dp[i] = max(dp[j],left);
      }
    }
    // for (int i=0;i<(1<<a);i++){
    //   cout << dp[i] << " " ;
    // }
    // cout << endl;
  }
  int ans = 0;
  for (int i=0;i<(1<<a);i++){
    int pos = 0, temp = 0;
    while(dp[i]>=2){
      if (dp[i]%2==1) temp += money[pos];
      pos++;
      dp[i] = (dp[i]>>1);
    }
    ans = max(ans,temp);
  }
  cout << ans;
}
