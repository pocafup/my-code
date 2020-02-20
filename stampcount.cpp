#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int mod = 1e9+7;
long long dp[1000000];

int main(){
  long long a,b,c; cin >> a >> b >> c;
  dp[0] = 1;
  for (int i=0;i<a;i++){
    for (int j=0;j<c;j++){
      if (i>=j){
        dp[i] += dp[i-j]*(b-1)%mod;
        dp[i] %= mod;
      }

    }
  }
  long long w = 1;
  for (int j=0;j<a;j++){
    w = (w%mod) * (b%mod);
    w %= mod;
  }
  w *= mod;
  for (int i=0;i<a;i++){
    cout << dp[i] << endl;
  }
  long long ans = w-dp[a-1]-dp[a-2]+w;
  cout << ans;
}
