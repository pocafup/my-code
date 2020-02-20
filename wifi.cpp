#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define INF 200000000;
int pos[2000];
double dp[2000];
double res[2000][2000];

int main(){
  int n,a,b; cin >> n >> a >> b;

  for (int i=0;i<n;i++) cin >> pos[i];
  sort(pos,pos+n);
  for (int i=0;i<2000;i++) dp[i] = INF;
  dp[0] = a;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      double num = double(abs(pos[i]-pos[j]))/2;

      res[i][j] = b*num+a;
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  for (int i=1;i<n;i++){
    for (int j=0;j<i;j++){
      if (j!=0){
        //cout << dp[i] << " fef" << endl;
        dp[i] = min(dp[i],min(dp[i-1]+a,dp[j-1]+res[j][i]));
      //  cout << dp[i] << " cfd" << endl;
      }else{
        dp[i] = min(dp[i-1]+a,res[j][i]);
        //cout << res[j][i] << " " << i << " " << dp[i] << endl;
      }
    }
    //cout << dp[i] << endl;

  }
//  cout << n-1 << endl;
  cout << setprecision(9);
  cout << dp[n-1];
}
