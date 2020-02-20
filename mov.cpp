#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
#define lowbits(x) x&-x
int dp[2][(1<<21)+1];
const int INF = -2*1e3;
vector<int> vec[25];
int pos[25];
int main(){
  int a,b; cin >> a >> b;
  for (int i=1;i<=a;i++){
    int c,d; cin >> c >> d;
    pos[i] = c;
    for (int j=0;j<d;j++){
      int e; cin >> e;
      vec[i].push_back(e);
    }
  }
  // cout << "r" << endl;
  for (int i=1;i<=(1<<a);i++){
    dp[0][i] = INF;
    dp[1][i] = INF;
  }
  for (int i=1;(1<<i)<=(1<<a);i++) if (vec[i][0]==0) dp[0][(1<<i)] = pos[i];
  int left,right;
  int keep = 0;
  // cout << "ee " << endl;
  // for(int i=0;i<(1<<a);i++){
  //   cout << dp[0][i] << " ";
  // }
  // cout << endl;
  for(int i=1;i<=a;i++){
    for (int j=1;j<=a;j++){
      int temp = j;

      while(temp){
        int cc = log2(lowbits(temp));
        // cout << "      zz = " << dp[0][j] << endl;
        int kk = dp[(i+1)%2][j];
        // cout << j << " " << k << endl;
        // cout << " kk = " << kk << endl;
        left = 0; right = vec[cc].size();
        while(left<right-1){
          int mid = ceil((left+right)/2);
          if (vec[cc][mid]<kk)left = mid;

          else right = mid;

        }
        if (vec[cc][right]<=kk && kk!=-2*1e3) keep = right;
        else keep = left;
        if (vec[cc][keep]<=kk){
          dp[i%2][j+cc] = max(dp[i%2][j+cc],vec[cc][keep]+pos[cc]);
          if (dp[i%2][j+cc]>b) {cout << i+1;exit(0);}
        }
        temp-=lowbits(temp);
      }
    }

  }
  cout << -1;
  // for(int i=0;i<a;i++){
  //   cout << dp[0][i] << " ";
  // }
}
