#include <iostream>
#include <algorithm>

using namespace std;
struct node{
  int x1, x2, y1, y2,len,width;
}rect[50001];
int tot = 0;
void add(int a, int b, int c ,int d){
  rect[++tot].x1 = a;
  rect[tot].y1 = b;
  rect[tot].x2 = c;
  rect[tot].y2 = d;
  rect[tot].len = c-a;
  rect[tot].width = d-b;
}
int peri_of(node a){
  return 2*(abs(a.x1-a.x2)+abs(a.y1-a.y2));
}
bool no_intersect(int a, int b){
  return max(rect[a].x1,rect[a].x2)<min(rect[b].x1,rect[b].x2) ||
         min(rect[a].x1,rect[a].x2)>max(rect[b].x1,rect[b].x2) ||
         max(rect[a].y1,rect[a].y2)<min(rect[b].y1,rect[b].y2) ||
         min(rect[a].y1,rect[a].y2)>max(rect[b].y1,rect[b].y2);
}
bool total_intersect(int a,int b){
  return rect[b].x2>=rect[a].x2 && rect[b].x1<=rect[a].x2 && rect[b].y2>=rect[a].y2 && rect[b].y1<=rect[a].y1;
}
int inter_len(int a, int b){
  return rect[a].len+rect[b].len-abs(max(rect[a].x2,rect[b].x2)-min(rect[a].x1,rect[b].x1));
}
int inter_width(int a, int b){
  return rect[a].width+rect[b].width-abs((max(rect[a].y2,rect[b].y2)-min(rect[a].y1,rect[b].y1)));
}
int partial_intersect(int a,int b){
  return 2*(inter_len(a,b)+inter_width(a,b));
}
int check_intersect(int a, int b){
  if (no_intersect(a,b)) return 0;
  if (total_intersect(a,b)) return peri_of(rect[a]);
  if (total_intersect(b,a)) return peri_of(rect[b]);
  return partial_intersect(a,b);
  return 0;
}
int main(){
  int n; cin >> n;
  int ans = 0;
  for (int i=0;i<n;i++){
    int a,b,c,d; cin >> a >> b >>c >> d;
    add(a,b,c,d);
    ans+= peri_of(rect[tot]);
  }
  for (int i=1;i<=n;i++){
    for (int j=i+1;j<=n;j++){
      ans -= check_intersect(i,j);
      // cout << ans << endl;
    }
  }
  cout << ans;
}

/*
7
-15 0 5 10
-5 8 20 25
15 -4 24 14
0 -6 16 4
2 15 10 22
30 10 36 20
34 0 40 16
*/
