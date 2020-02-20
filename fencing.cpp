#include <iostream>
#include <algorithm>

using namespace std;
#define pp pair<int,int>
int sz[20];
bool vis[20];
int n,q;
pp point[100005];
int main(){
  cin >> n >> q;
  memset(sz,-1,sizeof(sz));
  for(int i=0;i<n;i++) {
    cin >> point[i].first >> point[i].second;
    for (int j=0;j<20;j++)
  }
}

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int N=200200,M=200200;
const ll INF=4e18;
int n,m,cp,cl,r;
ll mx[M],mi[M];
struct vec{
    ll  x,y;
    vec(){}
    vec(ll  a,ll  b){x=a;y=b;}
    vec operator + (vec a){return vec(x+a.x,y+a.y);}
    vec operator - (vec a){return vec(x-a.x,y-a.y);}
    ll  operator ^ (vec a){return x*a.y-y*a.x;}
}p[N],h[N],di[M];
struct lin{vec d;int i;}L[M];
struct qry{int o;ll x,y,z;}q[M];
void upd(int i,ll x,ll y){
    ll va=x*q[i].x+y*q[i].y;
    mx[i]=max(mx[i],va);
    mi[i]=min(mi[i],va);
}
bool cmp(vec a,vec b){return a.x==b.x?a.y<b.y:a.x<b.x;}
bool cmp1(lin a,lin b){return (a.d^b.d)>0;}
bool cmp2(lin a,lin b){return (a.d^b.d)<0;}
void sol(int l,int r){
    if(l==r) return;
    int md=(l+r)>>1;
    sol(l,md),sol(md+1,r);cp=cl=0;
    FOR(i,l,  md) if(q[i].o==1) p[++cp]=vec(q[i].x,q[i].y);
    FOR(i,md+1,r) if(q[i].o==2) L[++cl]=(lin){di[i],i};
    if(!(cp*cl)) return;
    sort(p+1,p+cp+1,cmp);
    h[r=1]=p[1];
    FOR(i,2,cp){
        while(1<r && ((h[r]-h[r-1])^(p[i]-h[r]))<=0) r--;
        h[++r]=p[i];
    }
    sort(L+1,L+cl+1,cmp1);
    int j=1;
    FOR(i,1,r){
        for(;(i+1>r || (L[j].d^(h[i+1]-h[i]))>=0) && j<=cl;j++)
            upd(L[j].i,h[i].x,h[i].y);
    }//下凸包

    h[r=1]=p[1];
    FOR(i,2,cp){
        while(1<r && ((h[r]-h[r-1])^(p[i]-h[r]))>=0) r--;
        h[++r]=p[i];
    }
    sort(L+1,L+cl+1,cmp2);
    j=1;
    FOR(i,1,r){
        for(;(i+1>r || (L[j].d^(h[i+1]-h[i]))<=0) && j<=cl;j++)
            upd(L[j].i,h[i].x,h[i].y);
    }//上凸包
}
int main(){
    scanf("%d%d",&n,&m);m+=n;
    FOR(i,1,n) q[i].o=1,scanf("%lld%lld",&q[i].x,&q[i].y);
    FOR(i,n+1,m){
        scanf("%d",&q[i].o);
        if(q[i].o==1) scanf("%lld%lld",&q[i].x,&q[i].y);
        if(q[i].o==2){
            scanf("%lld%lld%lld",&q[i].x,&q[i].y,&q[i].z);
            if(q[i].y<0) q[i].x*=-1,q[i].y*=-1,q[i].z*=-1;
            if(q[i].y==0 && q[i].x<0) q[i].x*=-1,q[i].z*=-1;
            di[i]=vec(q[i].y,-q[i].x);
            mx[i]=-INF;mi[i]=INF;
        }
    }
    sol(1,m);
    FOR(i,n+1,m)if(q[i].o==2)
        mx[i]-q[i].z<0 || mi[i]-q[i].z>0?puts("YES"):puts("NO");
}
