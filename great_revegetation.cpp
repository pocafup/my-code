#include <iostream>
#include <algorithm>

using namespace std;
int fat[100001];
int n,m;
int father(int num){
  if (!fat[num]) return 0;
  if (fat[num]!=num) return father(fat[num]);
  return num;
}
void Union(int fir, int sec){
  if (father(fir) && father(sec)) fat[father(sec)] = father(fir);
  else if (!father(fir) && !father(sec)) {fat[fir] = fir;fat[sec] = fir;}
  else if (father(fir)){fat[sec] = father(fir);}
  else {fat[fir] = father(sec);}
}
void Break(int fir, int sec){
  if (father(fir) && father(sec)) return;
  else if (!father(fir) && !father(sec)) {fat[fir] = fir;fat[sec] = sec;}
}
bool vis[100001];
int main(){
  cin >> n >> m;
  for (int i=0;i<m;i++){
    char d;
    int x,y;
    cin >> d >> x >> y;

    if (d=='S') Union(x,y);
    else Break(x,y);
  }
  int ans = 0;
  for (int i=1;i<=n;i++){
    cout << father(i) << endl;
    if (vis[father(i)]) continue;
    else {vis[father(i)] = true; ans ++;}
  }
  cout << ans;
}
