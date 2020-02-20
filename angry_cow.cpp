#include <iostream>
#include <algorithm>

using namespace std;

#define INF 200000000;
int dp1[50000],dp2[50000],rad1[50000],rad2[50000];
int main(){

  int a; cin >> a;
  int b[a];
  sort(b,b+a);
  for (int i=0;i<a;i++) cin >> b[i];
  for (int i=0;i<50000;i++){
    dp1[i] = -INF;
    dp2[i] = -INF;
  }
  dp1[0] = 0;
  queue<int> q;
  int go = 0;
  q.push(b[0]);
  for (int i=1;i<a;i++){
    n = true;
    while(!q.empty() && n){
      if (q.front()+go+1<b[i]) q.pop();else n = false;
    }
    if (q.empty()) {
      dp[i] = b[i]-b[i-1];
      go = dp[i];
      q.push(b[i]);
    }else{
      go +=
    }
  }
}
