#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
// #define MAXN 1<<20
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
int n,m,pos[25],dp[(1<<20)+5],ans = 1e9;
vector<int> vec[25];
bool between(int a, int b, int c){
  if (a>b) swap(a,b);
  return c>=a && c<=b;
}
int bs(int ptr, int po){
  int le = 0, ri = vec[ptr].size()-1;

  while(ri>le+1){
    int mid = (ri+le)/2;
    if (vec[ptr][mid]<po) le = mid;
    else ri = mid;
  }
  if (vec[ptr][ri]<=po) return ri;
  if (vec[ptr][le]<=po) return le;
  return -1;
}
int main(){
  n = read(); m = read();
  for (int i=0;i<n;i++){
    int b; pos[i] = read(); b = read();
    for (int j=0;j<b;j++){
      int a; a = read();
      vec[i].push_back(a);
    }
  }
  for (int i=0;i<n;i++){
    if (vec[i][0]!=0) continue;
    dp[(1<<i)]=vec[i][0]+pos[i];
  }

  for (int i=1;i<(1<<n);i++){
    if (dp[i]) continue;
    for (int k=n-1;k>=0;k--){
      if ((i>>k)&1){
        int l = i-(1<<k);
        int re = bs(k,dp[l]);
        if(re!=-1){
          if (between(vec[k][re],vec[k][re]+pos[k],dp[l])){
            dp[i] = max(dp[i],vec[k][re]+pos[k]);

          }
        }
      }
    }
  }
  for (int i=1;i<(1<<n);i++){
    if (dp[i]>=m){
      int x = 0;
      for (int j=n;j>=0;j--){
        if ((i>>j)&1) x++;
      }
      ans = min(x,ans);
    }
  }
  if (ans>1e6) ans = -1;
  printf("%d",ans);
}
