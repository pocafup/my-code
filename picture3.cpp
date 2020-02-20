#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;
struct Point{
  int x,y,state;
}point[400005];
int n,tot=0,ans = 0;
void add(int xx, int yy, int st){
  point[++tot].x = xx;
  point[tot].y = yy;
  point[tot].state = st;
}
bool sorted(Point a, Point b){
  return a.x<b.x;
}
multiset<pair<int,bool> > se;
int addi;
int sweep(){
  int as = 0,ct = 0,bd = -1;
  for (multiset<pair<int,bool> >::iterator i = se.begin();i!=se.end();i++){
    cout << (*i).first-10000 << " " << (*i).second << "   ";
    if ((*i).second&& ct==0){
      ct++;as++;
      bd = (*i).first;
    }else if ((*i).second) ct++;
    else ct--;
    if (ct==0) addi+=(*i).first-bd;
  }
  cout << endl;
  return as;
}
int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    y1+=10000;y2+=10000;
    add(x1,y1,true);
    add(x1,y2,false);
    add(x2,y1,true);
    add(x2,y2,false);
  }
  sort(point+1,point+tot+1,sorted);
  int re_x = point[1].x;
  for (int i=1;i<=tot;i++){
    if (point[i].x!=re_x){
      int re = 0;addi = 0;
      // cout << se.size() << endl;
      re = sweep();
      if (se.size()) {
        multiset<pair<int,bool> >::iterator it = se.find(make_pair(point[i].y,true));
        multiset<pair<int,bool> >::iterator it2 = se.find(make_pair(point[i].y,false));
        if (it!=se.end()||it2!=se.end()) ans += addi;
      }
      ans += (point[i].x-re_x)*re*2;
      re_x = point[i].x;
    }
    if (se.size()){
      multiset<pair<int,bool> >::iterator it = se.find(make_pair(point[i].y,true));
      multiset<pair<int,bool> >::iterator it2 = se.find(make_pair(point[i].y,false));

      if (it!=se.end()) se.erase(it);
      else if (it2!=se.end()) se.erase(it2);
      else se.insert(make_pair(point[i].y,point[i].state));
    }else se.insert(make_pair(point[i].y,point[i].state));
  }
  cout << ans;
}
