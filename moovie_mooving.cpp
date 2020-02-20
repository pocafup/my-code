#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int dp[2][(1<<20)+1];
const int INF = -2*1e3;
vector<int> vec[21];
int pos[20];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++){
    int c,d; cin >> c >> d;
    pos[i] = c;
    for (int j=0;j<d;j++){
      int e; cin >> e;
      vec[i].push_back(e);
    }
  }
  // cout << "r" << endl;
  for (int i=0;i<(1<<a);i++){
    dp[0][i] = INF;
    dp[1][i] = INF;
  }
  for (int i=0;(1<<i)<(1<<a);i++) if (vec[i][0]==0) dp[0][(1<<i)] = pos[i];
  int left,right;
  int keep = 0;
  // cout << "ee " << endl;
  // for(int i=0;i<(1<<a);i++){
  //   cout << dp[0][i] << " ";
  // }
  // cout << endl;
  for(int i=1;i<=a;i++){
    for (int j=0;j<(1<<a);j++){
      for (int k=0;(1<<k)<(1<<a);k++){
        int cc = j%(1<<(k+1));
        // cout << "      zz = " << dp[0][j] << endl;
        if (cc<(1<<k)){
          int kk = dp[0][j];
          // cout << j << " " << k << endl;
          // cout << " kk = " << kk << endl;
          left = 0; right = vec[k].size()-1;
          while(left<right-1){
            int mid = ceil((left+right)/2);
            if (vec[k][mid]<kk)left = mid;

            else right = mid;

          }
          if (vec[k][right]<=kk && kk!=-2*1e3) keep = right;
          else keep = left;
          if (vec[k][keep]<=kk){
            dp[1][j+(1<<k)] = max(dp[1][j+(1<<k)],vec[k][keep]+pos[k]);
            if (dp[1][j+(1<<k)]>b) {cout << i+1;exit(0);}
          }
        }

      }


    }
    for (int k=1;k<(1<<a);k++){
      dp[0][k] = dp[1][k];
    }
  }
  cout << -1;
  // for(int i=0;i<a;i++){
  //   cout << dp[0][i] << " ";
  // }
}
