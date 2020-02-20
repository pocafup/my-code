#include <iostream>
#include <algorithm>

using namespace std;
struct node{
  int x1,y1,x2,y2;
}barn[50001];
bool sorted(node a, node b){
  return a.x1<b.x1 || (a.x1==b.x1 && a.y1<b.y1);
}
int main(){
  int n; cin >> n;
  for (int i=0;i<n;i++) cin >> barn[i].x1 >> barn[i].y1 >> barn[i].x2 >> barn[i].y2;
  sort(barn,barn+n,sorted);
}
