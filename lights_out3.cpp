#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> dp[(1<<7)+1][51];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> light[i];
  for (int i=0;j<b;j++) cin >> slot[i];
  int fir = 0;
  for (int i=0;i<7;i++) fir += light[i]*(1<<i);
  dp[fir][0]
}
