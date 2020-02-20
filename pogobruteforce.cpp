#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> pos[1001];
int dp[100][10000][2];

int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >> pos[i].first >> pos[i].second;
  sort(pos,pos+a);
  dp[0][pos[i].first][0] = pos[0].second;
  for (int i=1;i<a;i++){
    for (int j=0;j<10000;j++){

    }
  }
}
