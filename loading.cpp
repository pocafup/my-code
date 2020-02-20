#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
struct node{
  int x,y,up;
}cow[1005];
bool sorted(node a, node b){
  return a.y>b.y;
}
bool sorted2(node a, node b){
  return a.x<b.x;
}
int main(){
  ifstream cin ("balancing.in");
  ofstream cout ("balancing.out");
  int n; cin >> n;
  for (int i=0;i<n;i++) cin >> cow[i].x >> cow[i].y;
  sort(cow,cow+n,sorted);
  cow[0].up = 0;
  for (int i=1;i<n;i++){
    if (cow[i].y==cow[i-1].y) cow[i].up = cow[i-1].up;
    else cow[i].up = i;
  }
  sort(cow,cow+n,sorted2);
  int ans = 1e9;
  for (int i=0;i<n;i++){
    int y_bound = cow[i].y+1;
    int curr_up = 0, curr_down = 0, whole_up = cow[i].up, whole_down = n-cow[i].up;
    for (int j=0;j<n;j++){
      if (cow[j].y<y_bound) curr_down++;
      else curr_up++;
      ans = min(max(max(curr_up,whole_up-curr_up),max(curr_down,whole_down-curr_down)),ans);
    }
  }
  cout << ans;
}
