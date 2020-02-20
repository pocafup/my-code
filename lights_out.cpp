#include <iostream>
#include <algorithm>
using namespace std;
#define pp pair<int,int>
bool lights[51];
int a,b;
bool chain[b];
pp dp[(1<<7)][51][2];
int main(){
  cin >> a >> b;
  int on = 0,fir = 0;
  for (int i=0;i<a;i++) {cin >> lights[i]; on += lights[i];}
  for (int i=0;i<b;i++) {cin >> chain[i];on += chain[i]*(1<<i);}
  for (int i=0;i<b;i++) fir += lights[i]*(1<<i);
  for (int i=0;i<(1<<b);i++){
    for (int j=0;j<=a;j++){
      for (int k=0;k<2;k++){
        dp[i][j][k] = make_pair(-1,-1);
      }
    }
  }
  dp[fir][0][0]=
}
