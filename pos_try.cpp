#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define INF 20000000;
int main(){
  int a,b; cin >> a >> b;
  int pos[a];
  bool visited[a];
  memset(visited,0,sizeof(visited));
  for (int i=0;i<a;i++) cin >> pos[i];
  int go = b;
  int tim = 0;
  int ans = 0;
  for (int i=0;i<a;i++){
    int mini_dis = INF;
    int res = 0;
    int resp = 0;
    for (int j=0;j<a;j++){
      if (mini_dis>abs(go-pos[j]) && go-pos[j]!=0){
        if (!visited[j]){
          mini_dis = abs(go-pos[j]);
          res = pos[j];
          resp = j;
        }
      }
    }
    visited[resp] = true;
    go = res;
    //cout << mini_dis << endl;
    // for (int i=0;i<a;i++) cout << visited[i] << " ";
    // cout << endl;
    tim+=mini_dis;
    cout << tim << endl;
    ans+=tim;
  }
  cout << ans;
}
