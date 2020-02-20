#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int n,m;
int dp[5000][5000];

int fat[100001],level[100001];
char barn[100001];
int father(int x){
	if(fat[x]!=x)
	return father(fat[x]);
	else return x;
}
void Union(int x, int y){
  fat[y] = x;
}
void find_level(int a){
  if (fat[a]==a){level[a] = 0;return;}
  find_level(fat[a]);
  level[a] = level[fat[a]]+1;
}
void find_path(int x, int y, int k){
  // cout << x << " " << y << endl;
  if (dp[x][y]==3 || dp[x][y]==k) return;
  if (barn[x]==k||barn[y]==k) {dp[x][y] = k;return;}
  if (x==y) {dp[x][y] = k;return;}

  if (level[x]>level[y]) swap(x,y);
  if(level[x]<level[y]) {
    find_path(x,fat[y],k);
    if (dp[x][fat[y]]==barn[x]) dp[x][y] = barn[x];
    else dp[x][y] = 3;
  }
  if (level[x]==level[y] && x!=y){
    find_path(fat[x],fat[y],k);
    int r = dp[fat[x]][fat[y]];
    if(r==barn[x] && r==barn[y]){
      dp[x][y] = r;
    }else dp[x][y] = 3;
  }
}
int main(){
  ifstream cin ("milkvisits.in");
  ofstream cout ("milkvisits.out");

  cin >> n >>m;

  for (int i=1;i<=n;i++) {char d;cin >> d; barn[i] = (d=='G')?1:2;}
  for (int i=1;i<=n;i++) fat[i] = i;
  for (int i=0;i<n-1;i++){
    int a,b;cin >> a >> b;
    Union(a,b);
    // for (int i=1;i<=n;i++){
    //   cout << fat[i] << " ";
    // }
    // cout << endl;
  }
  // for (int i=1;i<=n;i++){
  //   cout << fat[i] << " ";
  // }
  for (int i=1;i<=n;i++){
    find_level(i);
    // cout << fat[i] << " " << i << endl;
    // cout << level[i] << endl;
  }
  for (int i=0;i<m;i++){
    int c,d; char e; cin >> c >> d >> e;
    if (c==d) {cout<<(barn[c]==e);continue;}
    int re = (e=='G')?1:2;
    find_path(c,d,re);
    cout << (re==dp[c][d]);
  }
}
