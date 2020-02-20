#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool sorted(pair<pair<int,int>,int> fi, pair<pair<int,int>,int> se){
    if (fi.first.second == se.first.second){
        return fi.first.first < se.first.first;
    }else{
          return fi.first.second<se.first.second;

    }
}
int main(){
  int a,b,c; cin >> a >> b >> c;
  pair<pair<int,int>,int> inv[b];
  for (int i=0;i<b;i++){
    cin >> inv[i].first.first >> inv[i].first.second >> inv[i].second;
  }
  sort(inv,inv+b,sorted);
  for (int i=0;i<b;i++){
    cout << inv[i].first.first << " " << inv[i].first.second << " " << inv[i].second << endl;
  }
  int dp[a+2][b+1];
  memset(dp,0,sizeof(dp));
  for (int j=0;j<b;j++){
    for (int i=1;i<a+2;i++){
      if (i==inv[j].first.second+1){
        if (inv[j].first.first>2){
          dp[i][j] = max(dp[i][j],dp[inv[j].first.first-2][j-1]+inv[j].second);

        }else{
          dp[i][j] = max(dp[i][j],dp[0][j-1]+inv[j].second);
        }
      }else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  for (int j=0;j<b;j++){
    for (int i=1;i<a+2;i++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
    cout << dp[a+1][b-1];
}
