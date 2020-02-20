#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define pp pair<int,int>
#define lowbits(x) x&-x
pp dp[(1<<7)+1][51];
int pos[51];
int pref[52];
string a,b;
int l,t,tog = 0,mini = 1e9;
int main(){
  cin >> l >> t;
  // for (int i=0;i<l;i++) cin >> pos[i];
  cin >> a >> b;
  cout << a.length() << " " << b.length() << endl;
  for (int i=0;i<a.length();i++) {
    pos[i] = (int)a[i]-48;
    pref[i] = (int)a[i]-48;
    if (i>0) pref[i]+=pref[i-1];
  }
  for (int i=0;i<b.length();i++) {
    // cout << (int)b[i]-48 << endl;
    // cout << (((int)b[i]-48)<<(t-i-1)) << " ";
    tog+=(((int)b[i]-48)<<(t-i-1));

  }

  memset(dp,0x3f3f,sizeof(dp));
  int temp = 0;
  for (int i=0;i<t;i++) temp+=(pos[i]<<(t-i-1));
  dp[temp][0] = make_pair(0,0);
  int li = 1e9;
  // cout << temp << " fff";
  for (int i=0;i<l-t+1;i++){
    for (int j=0;j<(1<<t);j++){
      if (dp[j][i].first<1000){
        cout << "      " << j << " " << i << " " << dp[j][i].first << " " << dp[j][i].second << endl;
        int still = 0,temp2 = j,left = pref[l-1]-pref[i+t-1];
        while(temp2){temp2-=lowbits(temp2);still++;}
        // cout << still << endl;
        cout << "ri " << left << " still " << still << " dp[j][i].second " << dp[j][i].second<< endl;
        if (li>still+i-dp[j][i].second+left) {li = still+i-dp[j][i].second+left;mini = dp[j][i].first;}
        else if (li==still+i-dp[j][i].second+left) mini = min(mini,dp[j][i].first);
        cout << "remain  = " << li << endl;

        // if (mini = min(mini,dp)
        // cout << "fe" << endl;
        int fir = (j>=(1<<(t-1))) ? 1 : 0;
        // cout << "er";
        int no_change = ((j-fir*(1<<(t-1)))<<1)+pos[i+t];
        // cout << "e";
        int change = ((j^tog-((fir^1)<<(t-1)))<<1) + pos[i+t];
        cout << "jowe " << ((j^tog-((fir^1)<<(t-1)))<<1) << endl;
        // cout << "k";
        int change_fir = (tog>=(1<<(t-1))) ? fir ? 1 : 0 : 0;
        cout << fir << " " << no_change << " " << change << " " << change_fir << endl;
        if (dp[no_change][i+1].first>dp[j][i].first) dp[no_change][i+1] = dp[j][i];
        // cout << "tiff" << endl;
        if (dp[change][i+1].first>dp[j][i].first) dp[change][i+1] = make_pair(dp[j][i].first+1,dp[j][i].second+change_fir);
        cout << "bof" << endl;
      }

    }
  }
  cout << mini;
}
