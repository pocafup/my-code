
#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct Cow{
  int x,y,radius;
}cow[100005];
void add(int a, int b, int c){
  cow[++tot].x = a;
  cow[tot].y = b;
  cow[tot].radius = c;
}
bool dist(Cow a, Cow b){
  return ((cow[a].x-cow[b].x)*(cow[a].x-cow[b].x)+(cow[a].y-cow[b].y)*(cow[a].y-cow[b].y))<=cow[a].radius*cow[a].radius;
}
void dfs(int pos){
  vis[pos] = true;
  for (int i=1;i<=tot;i++){
    if (dist(cow[i],cow[pos])){
      if (dp[i])
    }
  }
}
int main(){
  cin >> n;
  for (int i=0;i<n;i++){
    int a,b,c; cin >> a >> b >> c;
    add(a,b,c);
  }
  for (int i=1;i<=tot;i++) if (!vis[i]) dfs(i);
}
