#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <cstdio>
#include <cstring>
#include <utility>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define rei register int
#define BD 14
#define I 10100
#define pp pair<int,int>
int level[I],arr[I];
int ans[I][15],next,head[I],subsize[I],qt[I*6],other[I],seg[I*6];
int max(int a, int b) {return a > b ? a : b;}
inline int read() {
      int x=0,w=1;
      char ch;
      while(ch<'0'||ch>'9')
      {
          if(ch=='-')
              w=-1;
          ch=getchar();
     }
     while(ch>='0'&&ch<='9')
         x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
     return x*w;
 }
struct Edge{
  int to,cost,index;
};

vector<Edge> adj[I*6];
int LCA(int u, int v) {
	if(level[u] < level[v]) swap(u,v);

	int diff = level[u] - level[v];
	for(rei i=0; i<BD; i++) if((diff>>i)&1 ) u = ans[u][i];
	if(u == v) return u;
	for(rei i=BD-1; i>=0; i--) if(ans[u][i] != ans[v][i]) {
		u = ans[u][i];
		v = ans[v][i];
	}
	return ans[u][0];
}
void dfs(int pos, int lev, int prev){
  ans[pos][0] = prev;
  level[pos] = lev;
  subsize[pos] = 1;
  for (rei i=0;i<adj[pos].size();i++){
    int t = adj[pos][i].to;

    if (t==prev) continue;
    other[adj[pos][i].index] = t;
    dfs(t,lev+1,pos);
    subsize[pos]+= subsize[t];
  }
}
void set_up_lca(int nn){
  for(rei i = 1 ; i <= BD ; i++){
    for(rei j = 0; j < nn ; j++){
      if(ans[j][i-1] != -1) ans[j][i] = ans[ans[j][i-1]][i-1] ;
    }
  }
}
int num = 0,tot = 0,fat[I],chain_ind[I],chain_pos[I],chain_son[I],chain = 0;
void hld(int way, int cost, int prev){
  if (fat[chain]==-1) fat[chain] = way;
  chain_ind[way] = chain;
  chain_pos[way] = tot;
  arr[tot++] = cost;
  int son = -1, son_cost = 0;
  for (rei i=0;i<adj[way].size();i++){
    if(adj[way][i].to!=prev){
      if (son==-1||subsize[son]<subsize[adj[way][i].to]){
        son = adj[way][i].to;
        son_cost = adj[way][i].cost;
      }
    }
  }
  if (son==-1) return;
  hld(son,son_cost,way);
  for (rei i=0;i<adj[way].size();i++){
    if (adj[way][i].to!=son && adj[way][i].to!=prev){
      chain++;
      hld(adj[way][i].to,adj[way][i].cost,way);
    }
  }
}
void query_tree(int way, int le, int ri, int f, int t){
  if(le >= t || ri <= f) {
		qt[way] = -1;
		return;
	}
  if (le>=f && ri <= t) {qt[way] = seg[way];return;}
  int mid = (le+ri)/2;
  query_tree(way*2,le,mid,f,t);
  query_tree(way*2+1,mid,ri,f,t);
  qt[way] = max(qt[way*2],qt[way*2+1]);
}
void make_tree(int way, int le ,int ri){
  if (le == ri-1) {seg[way] = arr[le];return;}
  int mid = (le+ri)/2;
  make_tree(way*2,le,mid);
  make_tree(way*2+1,mid,ri);
  seg[way] = max(seg[way*2],seg[way*2+1]);
}
void update(int way, int le ,int ri, int go, int val){
  if(go<le || go>=ri) return;
  if (go==le && go==ri-1) {seg[way] = val; return;}
  int mid = (le+ri)/2;
  update(way*2,le,mid,go,val);
  update(way*2+1,mid,ri,go,val);
  seg[way] = max(seg[way*2],seg[way*2+1]);
}
void change(int i, int val) {
	int u = other[i];
	update(1, 0, tot, chain_pos[u], val);
}
int query_up(int fir, int sec){
  if (fir==sec) return 0;
  int from, to = chain_ind[sec], maxi = -1;
  while(true){
    from = chain_ind[fir];
    if (from == to){
      if (fir == sec) break;
      query_tree(1,0,tot,chain_pos[sec]+1,chain_pos[fir]+1);
      maxi = max(maxi,qt[1]);
      break;
    }
    query_tree(1,0,tot,chain_pos[fat[from]],chain_pos[fir]+1);
    maxi = max(maxi,qt[1]);
    fir = fat[from];
    fir = ans[fir][0];
  }
  return maxi;
}
void query(int fir, int sec){
  int lca = LCA(fir,sec);
  cout << max(query_up(fir,lca),query_up(sec,lca)) << endl;
}

int main(){
  ifstream cin ("desktop/P2898_2.in");
  ios_base::sync_with_stdio(0);

  auto start = high_resolution_clock::now();

  int T; cin >> T;
  while(T--){
    int n; cin >>  n;
    for (rei i=0;i<=n;i++) {
      adj[i].clear();
      fat[i] = -1;
      for (rei j=0;j<BD;j++) ans[i][j] = -1;
    }
    tot = 0;chain = 0;

    for (rei i=1;i<n;i++){
      int n1,n2,c;cin >> n1 >> n2 >> c;
      n1--;n2--;
      adj[n1].push_back((Edge){n2,c,i-1});
      adj[n2].push_back((Edge){n1,c,i-1});
    }
    dfs(0,0,-1);
    num = 0;
    hld(0,-1,-1);
    make_tree(1,0,tot);
    set_up_lca(n);
    while(true){
      char s[50]; cin >> s;

      if (s[3]=='E') break;
      int b,c;  cin >> b >> c;
      if (s[0] == 'Q') query(b-1,c-1);
      else {
        change(b-1,c);
      }
    }
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}
