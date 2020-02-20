#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <queue>
#include <cstdio>
#include <fstream>

using namespace std;
#define pp pair<long long,long long>
#define mp make_pair
long long maxi = 0, n,m, tot=0,head[100001];
struct Edge{
  long long to, next,cost,flow;
}edge[100001];
void add(long long x, long long y,long long co, long long fl){
  edge[++tot].to = y;
  edge[tot].cost = co;
  edge[tot].flow = fl;
  edge[tot].next = head[x];
  head[x] = tot;
}
bool vis[1001][1001];
long long dp[1001][1001];
void spfa(long long a, long long b){
  dp[a][b] = 0;
  vis[a][b] = true;
  queue<pp> q;
  q.push(mp(a,b));
  while(!q.empty()){
    long long qf = q.front().first;
    long long qs = q.front().second;
    vis[qf][qs] = false;
    q.pop();
    for(long long i=head[qf];i;i=edge[i].next){
      long long t = edge[i].to, flo = edge[i].flow;
      if (dp[t][min(qs,flo)]>dp[qf][qs]+edge[i].cost){
        dp[t][min(qs,flo)] = dp[qf][qs]+edge[i].cost;
        if (!vis[t][min(qs,flo)]) {vis[t][min(qs,flo)] = true;q.push(mp(t,min(qs,flo)));}
      }
    }
  }
}
inline long long read() {
      long long x=0,w=1;
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
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

int main(){
  setIO("pump");
  n = read(); m = read();
  for (long long i=0;i<m;i++){
    long long a,b,c,d; a = read(); b= read();c = read();d =read(); add(a,b,c,d); add(b,a,c,d);
  }
  memset(dp,0x3f3f3f3f,sizeof(dp));
  spfa(1,1000);
  for (long long i=1;i<1000;i++){
    if (dp[n][i]>1e9) continue;
    long long num = floor((double)(i*1e6)/(double)dp[n][i]);
    maxi = max(maxi,num);
  }
  printf("%lld",maxi);
}
