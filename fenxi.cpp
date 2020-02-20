#include <iostream>
#include <algorithm>

using namespace std;
int n,tot = 0,fat[100005];
struct Edge{
  int from,to,dis;
}edge[300005];
int father(int x){
	while(x!=fat[x]) x=fat[x]=fat[fat[x]];
	return x;
}
void Union(int x, int y){
  fat[father(y)] = father(x);
}
void add(int f, int t, int d){
  edge[++tot].from = f;
  edge[tot].to = t;
  edge[tot].dis = d;
}
bool sorted(Edge a, Edge b){
  return a.dis>b.dis;
}

int main(){
  int t; cin >> t;
  while(t--){
    cin >> n;
    memset(edge,0,sizeof(edge));
    tot = 0;
    for (int i=1;i<=n;i++) fat[i] = i;
    for (int i=0;i<n;i++){
      int a,b,c; cin >> a >> b >> c;
      add(a,b,c);
    }
    sort(edge+1,edge+tot+1,sorted);
    for (int i=1;i<=tot;i++){
      // cout << edge[i].dis << endl;
      if (edge[i].dis==1){
        Union(edge[i].from, edge[i].to);
      }else{
        if (father(edge[i].from)==father(edge[i].to)){cout << "NO" << endl;goto cde;}
      }
    }
    cout << "YES" << endl;
    cde:;
  }
}
