#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;
int pos[100001];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> pos[i];
  for (int i=0;i<a-1;i++){
    int c,d; cin >> c >> d;
    vec[c].push_back(d);
    vec[d].push_back(c);
  }
  for (int i=0;i<b;i++){
    int d,e,f; cin >> d >> e >> f;
    if (d==1){pos[e] = f;dijkstra(e)
  }
}
