#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
long long be[2005];
char give[2005],c;
long long dp[2005][2005];
int main(){
  long long a,b,d,e; cin >> a >> b;
  for (long long i=1;i<=b;i++) cin >> give[i];
  for (long long i=0;i<a;i++){
    cin >> c >> d >> e;
    be[(long long)c-'a'] = min(d,e);
  }

  for (long long i=0;i<=b;i++){
    for (long long j=0;j<=b;j++){
      dp[i][j] = 2*1e8;
    }
  }
  for (long long i=1;i<=b;i++){
    dp[i][i] = 0;
    if(give[i] == give[i+1]) dp[i][i+1] = 0;
  }
  //dp[0][0] = 0;
  for (long long i=0;i<=b;i++){
    for (long long j=1;j<=b;j++){
      long long k = j+i;
      long long g1 = (long long)give[j-1]-'a';
      long long g2 = (long long)give[k+1]-'a';
      //cout << g1 << " " << g2 << endl;
      if (give[j-1]==give[k+1]) dp[j-1][k+1] = min(dp[j-1][k+1],dp[j][k]);
      else{
        dp[j-1][k]=min(dp[j-1][k],dp[j][k]+be[g1]);
        dp[j][k+1]=min(dp[j][k+1],dp[j][k]+be[g2]);
      }

    }
  }
//   for (long long i=0;i<=b;i++){
//     for (long long j=0;j<=b;j++){
//       cout << dp[i][j] << " ";
//     }
//     cout << endl;
//   }
  cout << dp[1][b];
}
