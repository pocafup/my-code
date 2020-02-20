#include <iostream>
#include <algorithm>

using namespace std;
int n,fat[100005],sz[10005];

int father(int x){
	while(x!=fat[x]) x=fat[x]=fat[fat[x]];
	return x;
}

void update (int x,int y){
  sz[fat[x]]+=sz[x]+1;
  if (fat[x]==y) return;
  update(fat[x],y);
}
void Union(int x, int y){
  fat[father(y)] = father(x);
  update(y,x);
  // sz[fat[father(y)]] += sz[father(x)]+1;
}

int main(){
  int n; cin >> n;
  for (int i=1;i<=n;i++) {fat[i] = i;sz[i] = 0;}
  for (int i=0;i<n;i++){
    char a; cin >> a;
    if (a=='M'){
      int b,c; cin >> b >> c;
      Union(b,c);
    }else{
      int b; cin >> b;cout << sz[b] << endl;
    }
  }
}
