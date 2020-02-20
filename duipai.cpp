#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct ding{
    int x,y;
}p[600];
struct bian{
    int to,next;
}edge[300000];
ding f2[600],f[600];
int n,h[5]={0,-1,1,0,0},l[5]={0,0,0,1,-1};
int indx[50000];
int num=0,cnt=0,head[10000],dis[10000];
bool vis[10000];
bool check3(int x1,int y1,int x2,int y2,int x3,int y3)
{
//为了方便我们就把直角路径拆成两条来看
  if (x2==x3) return ((x1==x2)&&(y1>min(y2,y3))&&(y1<max(y2,y3)));
  else return ((y1==y2)&&(x1>min(x2,x3))&&(x1<max(x2,x3)));
}
bool check2(ding tot,int a,int b)
{
  bool fg=true;
  for (int i=1;i<=n;i++) if ((tot.x==f[i].x)&&(tot.y==f[i].y)) {fg=false;break;}//我们要保证直角上没有点
  fg=fg||(f2[a].x==f2[b].x)||(f2[a].y==f2[b].y);
//当然如果两个点原本就在同一列或同一行的话，那就不存在直角了。。。
  for (int i=1;i<=n;i++)
  if (check3(f[i].x,f[i].y,f2[a].x,f2[a].y,tot.x,tot.y)||check3(f[i].x,f[i].y,f2[b].x,f2[b].y,tot.x,tot.y))
//检查枚举的这条直角路径上有没有点，如果有，那么这条路径禁止通行
  {fg=false; break;}
  if (fg) return true;
  return false;
}
bool check1(int a,int b)
{
//一般情况下两点间的的直角路径有两条，所以我们也分类讨论
  ding tot; tot.x=f2[a].x; tot.y=f2[b].y;
  if (check2(tot,a,b)) return true;
   tot.x=f2[b].x; tot.y=f2[a].y;
  if (check2(tot,a,b)) return true;
  return false;
}
void add(int u,int v)
{
  edge[++num].to=v;
  edge[num].next=head[u];
  head[u]=num;
}
int calc(int a,int b){return (abs(f2[a].x-f2[b].x)+abs(f2[a].y-f2[b].y));}
//计算两点间的曼哈顿距离
int dijkstra(int a,int b)
{
  for (int i=1;i<=cnt;i++) {dis[i]=2100000000; vis[i]=false;}
//赋初值
  for (int i=1;i<=n;i++) if ((indx[i]!=b)&&(indx[i]!=a)) vis[indx[i]]=true;
//除了起点与终点外，其他原本就存在的点是不能用于更新最短路径的，因为它们只能被经过一次
  dis[a]=0;
  for (int i=1;i<=cnt;i++)
  {
      int now=1;
      for (int j=1;j<=cnt;j++) if (((dis[j]<dis[now])||(vis[now]))&&(!vis[j])) now=j;
//如果说已经没有没被更新过的点，或者点与点之间已经没路了，返回-1；
      if ((vis[now])||(dis[now]==2100000000)) return -1;
      if (now==b) return dis[b];
//如果终点成了目前离起点最近的未更新过其他点的点，那么说明剩下的点已经没办法再更新这条最短路了，直接返回答案
      vis[now]=true;
      for (int j=head[now];j;j=edge[j].next)
      {
        int y1=edge[j].to;
      if (!vis[y1]) dis[y1]=min(dis[y1],dis[now]+calc(now,y1));
    }
  }
  return -1;
}
int main()
{
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
  {
    scanf("%d%d",&p[i].x,&p[i].y);
    ding tot; tot.x=p[i].x; tot.y=p[i].y;
    f[i]=tot;
//定义一个结构体来储存只是为了方便。。。p[i]数组是没用的。。。
  }
  for (int i=1;i<=n;i++)
  {
    f2[++cnt]=f[i]; indx[i]=cnt;//储存扩展后的点，并记录原点在数组中的位置
    for (int j=1;j<=4;j++)
    {
     bool fg=true;
     ding tot;tot.x=p[i].x+h[j]; tot.y=p[i].y+l[j];
//枚举扩展点
     for (int k=1;k<=n;k++) if ((tot.x==f[k].x)&&(tot.y==f[k].y)) {fg=false;break;}
//保证原本这个位置上是没有点的
     if (fg) f2[++cnt]=tot;
    }
  }
  for (int i=1;i<=cnt;i++)
   for (int j=i+1;j<=cnt;j++)
   if (check1(i,j)) {add(i,j);add(j,i);}
//检查这两点间是否能到达，如果可以，那么就用链式前向星记录下来（好像可以不用，但是我当时以为。。）
   int ans=0;
  for (int i=1;i<=n;i++)
  {
      int sum=0;
      if (i!=n) sum=dijkstra(indx[i],indx[i+1]);
      else sum=dijkstra(indx[i],indx[1]);
//计算它与它要到达的点间的最短距离
      if (sum==-1) {cout<<"-1"<<endl; return 0;}
//如果返回-1，说明两点间无法到达
      else ans+=sum;
//否则记录
  }
  printf("%d\n",ans);
  return 0;
}
