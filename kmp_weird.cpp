#include<cstdio>
#include<cstring>
#include<iostream>
#define lowbit(x) (x&-x)
using namespace std;
const int N=1e5+50;
int a[N],b[N],s[30],nxt[N],n,m,res;
int small[N],sma[N]; // 分别表示 小于 小于等于的个数
int sta[N],top;
void add(int x,int c) {for(;x<=25;x+=lowbit(x)) s[x]+=c;}
int get(int x) {res=0;for(;x>0;x-=lowbit(x)) res+=s[x];return res;}
int main(){
    scanf("%d%d%*d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]),small[i]=get(b[i]-1),
        sma[i]=get(b[i]),add(b[i],1);
    //sma[m+1]=small[m+1]=-1;
    memset(s,0,sizeof(s));
    nxt[0]=-1;
    for(int i=2,j=-1;i<=m;i++) // 模式串 第二个开始匹配
    {
        while((get(b[i]-1)!=small[j+1]||get(b[i])!=sma[j+1])&&j)//2种case
        {
            for(int k=i-j;k<=i-nxt[j]-1;k++) add(b[k],-1);
            j=nxt[j]; // 匹配失败 跳转nxt  更新树状数组
        }
        if(get(b[i]-1)==small[j+1]&&get(b[i])==sma[j+1]) j++;
        nxt[i]=j; add(b[i],1);
        cout << j << " ";
    }
    cout << endl;
    memset(s,0 ,sizeof(s));
    for(int i=1,j=0;i<=n;i++) // 匹配串 第一个开始匹配
    {
        while((get(a[i]-1)!=small[j+1]||get(a[i])!=sma[j+1])&&j)
        {
            for(int k=i-j;k<=i-nxt[j]-1;k++) add(a[k],-1);
            j=nxt[j]; // 匹配失败 跳转nxt
        }
        if(get(a[i]-1)==small[j+1]&&get(a[i])==sma[j+1]) j++;
        if(j==m) sta[++top]=i-m+1;
        add(a[i],1);
        cout <<  j << " ";
    }
    cout << endl;
    printf("%d\n",top);
    for(int i=1;i<=top;i++) printf("%d\n",sta[i]);
    return 0;
}
