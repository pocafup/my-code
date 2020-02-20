#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN 255*2005
const int MOD = 1e6;
int n,pos[255],dp[MAXN],closest = 1e9, sum = 0,ke = -1;

int main(){
  cin >> n;
  for (int i=0;i<n;i++) {cin >> pos[i];sum+=pos[i];}
  dp[0] = 1;
  for (int i=0;i<n;i++){
    for(int j=floor(sum/2);j>0;j--){
      if (j>=pos[i]) if (dp[j-pos[i]]) dp[j] += dp[j-pos[i]];
      if (dp[j] && closest>abs(j-ceil(sum/2))){
        closest = abs(j-ceil(sum/2));
        ke = j;
      }

      dp[j]%=MOD;
    }
  }
  cout << dp[ke] << endl << sum-ke*2;
}
