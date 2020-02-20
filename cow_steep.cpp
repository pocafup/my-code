#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
int colli[100005];
int n;
struct Point{
  int x1,y1,x2,y2,id;
}point[100001];
int tot = 0;
void add(int x, int y, int xx ,int yy,int d){
  if (x>xx) {swap(x,xx);swap(y,yy);}
  point[++tot] = (Point){x,y,xx,yy,d};
}
bool sorted(Point a, Point b){
  return a.x1<b.x1;
}
char get_line_intersection(Point a, Point b){
    float p0_x = a.x1, p0_y = a.y1, p1_x = a.x2,  p1_y = a.y2,
    p2_x= b.x1,  p2_y = b.y1,  p3_x = b.x2, p3_y = b.y2;
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;
    s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;
    s2_y = p3_y - p2_y;
    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);
    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)return 1;
    return 0;
}
int re = 1e9;
void inc(int fir, int sec){
  colli[fir]++;colli[sec]++;
}
int ke = 1;
int main(){
  ofstream cout("cowjump.out");
  ifstream cin("cowjump.in");
  cin >> n;
  for (int i=1;i<=n;i++){
    int a,b,c,d; cin >> a >> b >> c >> d;
    add(a,b,c,d,i);
  }
  sort(point+1,point+tot+1,sorted);
  for (int i=1;i<=tot;i++){
    int ptr = i+1;
    while (point[ptr].x1<=point[i].x2){
      if (get_line_intersection(point[ptr],point[i])) inc(ptr,i);
      ptr++;if (ptr>tot) break;
    }
  }
  for (int i=1;i<=n;i++){

    if (colli[i]>ke) {ke = colli[i];re = point[i].id;}
    else if (colli[i]==ke) {re = min(re,point[i].id);}
  }
  cout << re;
}
