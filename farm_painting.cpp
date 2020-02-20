#include <iostream>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;
#define pp pair<int,int>
struct Rect{
  int x1,y1,x2,y2;
}rect[200005];
struct Edge{
  int x,pos;
  bool start;
}point[400005];
bool vis[200005];
multiset<pp> se;

bool sorted(Edge a, Edge b){
  return a.x<b.x;
}
int main(){
  int n; cin >> n;
  int ans = 0;
  for (int i=0;i<n;i++){
    cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;
    point[i*2] = (Edge){rect[i].x1,i,1};
    point[i*2+1] = (Edge){rect[i].x2,i,0};
  }
  sort(point,point+2*n,sorted);
  se.insert(make_pair(1e9,1));
  for (int i=0;i<2*n;i++){
    int ef = point[i].pos;
    int st = point[i].start;
    pair<int,int> fin = *(se.lower_bound(make_pair(rect[ef].y1,0)));
    if (st){
      if (fin.second==1){
        ans++;
        vis[ef] = true;
        se.insert(make_pair(rect[ef].y1,1));
        se.insert(make_pair(rect[ef].y2,0));
      }
    }else{
      if (vis[ef]){
        se.erase(se.find(make_pair(rect[ef].y1,1)));
        se.erase(se.find(make_pair(rect[ef].y2,0)));
      }
    }
  }
  cout << ans;
}
