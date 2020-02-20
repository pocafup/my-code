#include <iostream>
#include <algorithm>

using namespace std;
int a;
pair<int,int> b[10000];
bool compare(pair<int,int> z, pair<int,int> zz){
  return z >zz;
}
int ans(){
  int dp[a][a],ansv =0;
  for (int i=0;i<a;i++){
    dp[i][i] = b[i].second;
  }
  for (int j=a-1;j>=0;j--){
    for (int i=0;i<j;i++){
      dp[i][j] = b[i].second +b[j].second;
      int k = a-1;
      while (k>=0 && abs(b[k].first - b[j].first)>= abs(b[j].first-b[i].first)){
        dp[i][j] = max(dp[i][j], dp[j][k] + b[i].second);
        k--;
      }
      ansv = max(ansv,dp[i][j]);

    }
  }
  return ansv;
}

int main(){

  cin >> a;
  for (int i=0;i<a;i++){
    cin >> b[i].first >> b[i].second;
  }
  sort(b,b+a);
  // for (int i=0;i<a;i++){
  //   cout << b[i].first << " " << b[i].second << endl;
  // }
  int m = ans();
  sort(b,b+a,compare);
  m = max(m,ans());
  cout << m;
}
