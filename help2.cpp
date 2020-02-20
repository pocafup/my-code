#include <stdio.h>
int main() { int a; //马路长度 int b[100000]={0}; //0为无，1为有 int m; //区域数目 int n[100]; //起始区域 int j[100]; //终止区域 scanf("%d %d",&a,&m); int i; int e; for(e=0;e<=a;e++) { b[e]=1;
} for(i=0;i<m;i++) { scanf("%d %d",&n[i],&j[i]); } int u,y; for(u=0;u<m;u++) { for(y=n[u];y<=j[u];y++) { b[y]=0; } } int h; int ji=0; for(h=0;h<10001;h++) { if(b[h]==1) { ji++; } } printf("%d",ji); }
