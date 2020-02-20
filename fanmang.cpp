#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <stdio.h>

using namespace std;
#define pp pair<long long,long long>
pp coord[1001];
long long tot = 0,edg = 0;
double len = 0;
struct node{
  long long from,to;
  double dis;
}edge[600010];
long long fat[1001];
void add(long long x, long long y, double z){
  edge[++tot].from = x;
  edge[tot].to = y;
  edge[tot].dis = z;
}
long long father(long long x){
	if(fat[x]!=x)
	return father(fat[x]);
	else return x;
}
void Union(long long x, long long y){
  fat[father(y)] = father(x);
}
bool vis[1001][1001];
double dis(pp aa, pp bb){
  return (double)sqrt((aa.first-bb.first)*(aa.first-bb.first)+(aa.second-bb.second)*(aa.second-bb.second));
}
bool sorted(node aa, node bb){
  return aa.dis<bb.dis;
}
int main(){
  long long a,b; cin >> a >> b;
  // for (long long i=1;i<=a;i++) cin >> coord[i].first >> coord[i].second;

  for (long long i=0;i<b;i++) {
    long long d,e,f; cin >> d >> e >> f;
    add(d,e,f);
  }
  // for (long long i=1;i<=a;i++){
  //   for (long long j=i+1;j<=a;j++){
  //     add(i,j,dis(coord[i],coord[j]));
  //   }
  // }
  sort(edge+1,edge+tot+1,sorted);
  for (long long i=1;i<=a;i++) fat[i] = i;
  for (long long i=1;i<=tot;i++){
    if (edg==a-1)break;
    if (father(edge[i].from)!=father(edge[i].to)){
      Union(edge[i].from,edge[i].to);
      len=max(edge[i].dis,len);
      edg++;
    }
  }
  cout << edg << " " << len;
}
