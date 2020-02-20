#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
#define pp pair<int,int>
pp pos[100001];
struct Edge{
  int x,y,stat,in;
}edge[200005];
int tot = 0;
bool sorted(Edge a, Edge b){
  return a.x<b.x || (a.x==b.x && a.stat<b.stat);
}
multiset<pair<int,bool > > se;

void add(int xx,int yy, bool stats,bool go){
  edge[++tot].x = xx;
  edge[tot].y = yy;
  edge[tot].stat = stats;
  edge[tot].in = go;
}
int sweep(){
  multiset<pair<int,bool > > tmp;
  tmp = se;

}
int main(){
  // ofstream cout("paintbarn.out");
  // ifstream cin("paintbarn.in");
  int a,b; cin >> a >> b;
  int x1,y1,x2,y2;
  for (int i=0;i<a;i++){
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1<y2) swap(y1,y2);
    add(x1,y1,true,true);
    add(x1,y2,true,false);
    add(x2,y1,false,true);
    add(x2,y2,false,false);
  }
  sort(edge+1,edge+tot+1,sorted);
  int ans = 0;
  int x_pos = 0;
  for (int i=1;i<=tot;i++){
    if (x_pos!=edge[i].x){
      ans += (x_pos-edge[i].x)*sweep();
      x_pos = edge[i].x;
    }else if (edge[i].stat == false) se.erase(se.find(make_pair(edge[i].y,edge[i].in)));
    else se.insert(make_pair(edge[i].y,edge[i].in));
  }
  cout << ans;
}
