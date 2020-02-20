#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  char c[a+1];

  for (int i=0;i<a;i++){
    cin >> c[i];
  }

  int dp[a+1][b+1][3];
  memset(dp,0,sizeof(dp));
  char eat[3] = {'H','P','S'};
  char beat[3] = {'S','H','P'};
  for (int i=0;i<3;i++){
    for (int j=1;j<a+1;j++){
      if (beat[i] == c[j-1]){
        dp[j][b-1][i] = dp[j-1][b-1][i]+1;
      }else{
        dp[j][b-1][i] = dp[j-1][b-1][i];
      }
      cout << dp[j][b-1][i] << " ";
    }
    cout << endl;
  }

  for (int j=1;j<b+1;j++){
    for (int i=1;i<a+1;i++){
      for (int k=0;k<3;k++){
        for (int z=0;z<3;z++){
          if (z!=k){
            if (eat[z] == beat[k]){
              dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-1][z]+1);
              cout << dp[i][j][k] << " ee" << endl;

            }
          }
        }
      }
    }
  }
  for (int k=0;k<3;k++){
    for (int j=0;j<b+1;j++){
      for (int i=0;i<a+1;i++){

        cout << dp[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl << endl;
  }

}
