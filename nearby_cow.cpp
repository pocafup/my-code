#include <cstdio>
int max(int a, int b){return a>b? a:b;}
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
int n,k;
struct Edge{
  int from,to,next;
}edge[200005];
int tot = 0,head[100005];
void add(int f, int t){
  edge[++tot].from = f;
  edge[tot].to = t;
  edge[tot].next = head[f];
  head[f] = tot;
}
int dp[100005][25];
int main(){
  n = read(); k = read();
  for (int i=0;i<n-1;i++){
    int a,b; a =read(); b = read();
    add(a,b); add(b,a);
  }
  for (int i=1;i<=n;i++) dp[i][0] = read();;
  for (int i=1;i<=k;i++){
    for (int j=1;j<=n;j++){
      dp[j][i] = dp[j][max(0,i-2)];
      for (int l=head[j];l;l=edge[l].next){
        int t = edge[l].to;
        dp[j][i]+=dp[t][i-1]-dp[j][i-2];
      }
    }
  }
  for (int i=1;i<=n;i++) printf("%d\n",dp[i][k]);
}
