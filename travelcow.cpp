#include <iostream>
#include <algorithm>

using namespace std;

int grid[101][101];
int dp[101][101][16];
int ways[101][101];
int main(){
  int a,b,c; cin >> a >> b >> c;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      char d; cin >> d;
      if (d == '.') grid[i][j] = 0;
      else grid[i][j] = 1;
    }
  }
  int p1,p2,p3,p4; cin >> p1 >> p2 >> p3 >> p4;
  p1--;p2--;p3--;p4--;
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  int ans = 0;
  ways[p1][p2] = 1;
  for (int i=0;i<c;i++){
    cout << i << endl;
    for (int j=0;j<a;j++){
      for (int k=0;k<b;k++){
        for (int l=0;l<4;l++){
          if (j+x[l]>=0 && j+x[l]<a && k+y[l]>=0 && k+y[l]<b){
            if (grid[j+x[l]][k+y[l]]!=1 && grid[j][k]!=1){
              dp[j][k][i] += ways[j+x[l]][k+y[l]];
            }
          }
        }
      }
    }
    for (int j=0;j<a;j++){
      for (int k=0;k<b;k++){
        ways[j][k] = max(ways[j][k],dp[j][k][i]);
      }
    }
    for (int j=0;j<a;j++){
      for (int k=0;k<b;k++){
        cout << dp[j][k][i] << " ";
      }
      cout << endl;
    }
  }
  for (int j=0;j<a;j++){
    for (int k=0;k<b;k++){
      cout << ways[j][k] << " ";
    }
    cout << endl;
  }
  cout << ways[p3][p4];
}
