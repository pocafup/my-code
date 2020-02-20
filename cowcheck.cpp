#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  pair<int,int> h[a],g[b+1];
  for(int i=0;i<a;i++) cin >> h[i].first >> h[i].second;
  for(int i=1;i<b+1;i++) cin >> g[i].first >> g[i].second;
  int dp[a+1][b+1][2];
  int x1,x2,y1,y2;
  int dis;
  memset(dp,10000,sizeof(dp));
  dp[0][0][0] = 0;
  for (int i=1;i<a;i++){
    dp[i][0][0] = dp[i-1][0][0]+(h[i].first-h[i-1].first)*(h[i].first-h[i-1].first)+(h[i].second-h[i-1].second)*(h[i].second-h[i-1].second);
    //cout << dp[i][0][0] << " " << h[i].first << " " << h[i].second << " " << h[i-1].first << " " << h[i-1].second<< endl;
  }

  for (int j=1;j<b+1;j++){
    for (int i=0;i<a;i++){
      for (int k=0;k<2;k++){
        if (k==0 && i==0){
          continue;
        }else if (i==0 && j==1){
          x1 = h[0].first;
          x2 = g[1].first;
          y1 = h[0].second;
          y2 = g[1].second;
          dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
          dp[i][j][k] = dp[0][0][0]+dis;
        }else if (i==0){
          x1 = g[j].first;
          x2 = g[j-1].first;
          y1 = g[j].second;
          y2 = g[j].second;
          dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
          dp[i][j][k] = dp[i][j-1][k]+dis;
        }else if (k==0){
          x1 = g[j].first;
          x2 = h[i].first;
          y1 = g[j].second;
          y2 = h[i].second;
          dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
          dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][0]+dis);
          x1 = h[i-1].first;
          x2 = g[j].first;
          y1 = h[i-1].second;
          y2 = g[j].second;
          dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
          dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][1]+dis);
        }else if(k==1){
          x1 = g[j-1].first;
          x2 = g[j].first;
          y1 = g[j-1].second;
          y2 = g[j].second;
          dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
          dp[i][j][k] = min(dp[i][j][k],dp[i][j-1][0]+dis);
          x1 = h[i].first;
          x2 = g[j].first;
          y1 = h[i].second;
          y2 = g[j].second;
          dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
          dp[i][j][k] = min(dp[i][j][k],dp[i][j-1][1]+dis);
        }
      }
    }
  }
  for (int j=0;j<b+1;j++){
    for (int k=0;k<2;k++){
      for (int i=0;i<a;i++){
        cout << dp[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

}
