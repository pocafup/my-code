  #include <iostream>
#include <algorithm>

using namespace std;

long long n,k;
struct Edge{
  long long from,to,dis;
}edge[7505*3750];
long long tot = 0,fat[7505];

long long father(long long x){
  while(x!=fat[x]) x=fat[x]=fat[fat[x]];
  return x;
}
void Union(long long x, long long y){
  fat[father(y)] = father(x);
}
bool sorted(Edge a, Edge b){
  return a.dis<b.dis;
}
int main(){
  cin >> n >> k;
  long long len = 0;
  for (long long i=1;i<=n;i++){
    for (long long j=i+1;j<=n;j++){
      edge[++tot] = (Edge){i,j,(i*2019201913+2019201949*j) % 2019201997};
    }
  }
  // sort(edge+1,edge+tot+1,sorted);
  for(int i=1;i<=n;i++) fat[i] = i;
  long long edg = n;
  for (long long i=1;i<=tot;i++){
    // cout << edge[i].dis << " " << father(edge[i].from) << " " << father(edge[i].to) << endl;
    if (edg==k&&father(edge[i].from)!=father(edge[i].to)) {len = edge[i].dis;break;}
    if (edg!=k&&father(edge[i].from)!=father(edge[i].to)){
      Union(edge[i].from,edge[i].to);
      edg--;
    }
  }
  cout << len;
}
