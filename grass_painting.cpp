/*
ID:dx424391
PROG: planting
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

pair<int,int> pos[100001];
int node[100001];
int main(){
  ofstream cout("planting.out");
  ifstream cin ("planting.in");
  int a; cin >> a;
  for (int i=0;i<a-1;i++){
    int c,d; cin >> c >> d;
    node[c]++; node[d]++;
  }
  int ans = 0;
  for (int i=0;i<a;i++){
    ans = max(node[i],ans);
  }
  cout << ans+1;
}
