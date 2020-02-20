#include <iostream>
#include <algorithm>

using namespace std;
int n,k;
string s;
int fat[100005],head[100005],level[100005],fat[100005];

struct Edge{
  int from,to,next;
}edge[100005];
void add(int a, int b){
  edge[++tot].from = a;
  edge[tot].to = b;
  edge[tot].next = head[a];
  heat[a] = tot;
}
int arr[100005],id = 0, son[100005];
set<int> seg[400005];
void dfs(int pos, int prev){
  sz[pos] = 1;
  arr[++id] = pos;
  level[pos] = level[prev]+1;
  fat[pos] = prev;
  for (int i=head[pos];i;i=edge[i].next){
    int t= edge[i].to;
    if (t!=prev) dfs(t,pos);
    sz[pos] += sz[t];
    if (!son[pos]||sz[son[pos]]<sz[t]) son[pos] = t;
  }
}

void make_tree(int way, int le, int ri){
  for (int i=le;i<=ri;i++) seg[way].insert(arr[i]);
  if (le==ri) return;
  int mid = (le+ri)/2;
  
}
int main(){
  cin >> n >> k;
  cin >> s;
  for (int i=0;i<n-1;i++){
    int a,b; cin >> a >> b;
    add(a,b);
  }
  memset(fat,-1,sizeof(fat));
  dfs(1,0);
  make_tree(1,1,id);
}
