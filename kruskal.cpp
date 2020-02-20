#include <iostream>
#include <algorithm>

using namespace std;
int a,b,tot=0,len=0,edg = 0;
#define ri register int
struct node{
  int from,to,dis;
}edge[400010];
int fat[5001];
void add(int x, int y, int z){
  edge[++tot].from = x;
  edge[tot].to = y;
  edge[tot].dis = z;
}

int father(int x){
	if(fat[x]!=x)
	return father(fat[x]);
	else return x;
}
void Union(int x, int y){
  fat[father(y)] = father(x);
}
bool sorted(node aa, node bb){
  return aa.dis < bb.dis;
}
int main(){
  cin >> a >> b;
  for (int i=0;i<b;i++){
    int c,d,e;cin >> c >> d >> e;
    add(c,d,e);
    add(d,c,e);
  }
  sort(edge+1,edge+tot+1,sorted);
  for (int i=1;i<=a;i++) fat[i] = i;
  for (int i=1;i<=tot;i++){
    if (edg==a-1) break;
    if (father(edge[i].from)!=father(edge[i].to)){
      Union(edge[i].from,edge[i].to);
      len += edge[i].dis;
      edg++;
    }
  }
  cout << len;
}
