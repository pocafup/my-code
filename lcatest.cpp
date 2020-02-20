#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N=10000+5;
vector <int> son[N];
int T,n,depth[N],fa[N][20],in[N],a,b;
void dfs(int prev,int rt){
    depth[rt]=depth[prev]+1;
    fa[rt][0]=prev;
    for (int i=1;i<20;i++)
        fa[rt][i]=fa[fa[rt][i-1]][i-1];
    for (int i=0;i<son[rt].size();i++)
        dfs(rt,son[rt][i]);
}
int LCA(int x,int y){
    if (depth[x]<depth[y])
        swap(x,y);
    for (int i=19;i>=0;i--)
        if (depth[x]-(1<<i)>=depth[y])
            x=fa[x][i];
    if (x==y)
        return x;
    for (int i=19;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int main(){
    int k;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        son[i].clear();
    memset(in,0,sizeof in);
    for (int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        son[a].push_back(b);
        in[b]++;
    }
    depth[0]=-1;
    int rt=0;
    for (int i=1;i<=n&&rt==0;i++)
        if (in[i]==0)
            rt=i;
    dfs(0,rt);
    for (int i=0;i<k;i++){
      scanf("%d%d",&a,&b);
      printf("%d",level[fa[i].first]+level[Q[i].second]-2*level
                  [lca(Q[i].first,Q[i].second)] << endl;
    }


    return 0;
}
