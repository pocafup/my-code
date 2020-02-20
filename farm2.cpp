#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
struct node{
  int x1,y1,x2,y2;
}barn[50001];
bool vis[50001];
bool sorted(node a, node b){
  return a.x1<b.x1 || (a.x1==b.x1 && a.x2>b.x2);
}
bool contained(node a, node b){
  return a.x1<=b.x1 && a.y1<=b.y1 && a.x2>=b.x2 && a.y2>=b.y2;
}
int main(){
  int n; cin >> n;
  int ans = n;
  for (int i=0;i<n;i++) cin >> barn[i].x1 >> barn[i].y1 >> barn[i].x2 >> barn[i].y2;
  sort(barn,barn+n,sorted);
  for (int i=0;i<n;i++){
    if (vis[i]) continue;
    vis[i] = true;
    int curr = i+1;
    while(barn[i].x1<=barn[curr].x1){
      if (!vis[curr] && contained(barn[i],barn[curr])) {vis[curr] = true;curr++;ans--;}
      else curr++;

      if (curr>=n) break;
    }
  }
  cout << ans;
}
