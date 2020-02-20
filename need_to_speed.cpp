#include <iostream>
#include <string>

using namespace std;

void solve(){
  int a,b,c;
  int d[1000][1000];
  int e[1000];
  cin >> a >> b >> c;
  for(int i=0;i<c;i++){
    cin >> d[i][0] >> d[i][1];
    d[i][2] = int(d[i][0]) / int(d[i][1]);
  }
}

int main(){
  solve();
}
