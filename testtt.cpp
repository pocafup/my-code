#include<bits/stdc++.h>
#include<stack>
#include<queue>
using namespace std;
inline int read(){
    int w=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        w=(w<<3)+(w<<1)+ch-48;
        ch=getchar();
    }
    return w*f;
}
int dfn[100010],low[100010],size[100010],col[100010],color,cnt,head[1000010],n,m,tim,head1[1000010],cntt,dis[100010][2];
bool vis[100010],debug;
struct Edge1{
    int from,to,next;
}edge1[1000010];
inline void addedge1(int u,int v){
    cnt++;
    edge1[cnt].from=u;
    edge1[cnt].to=v;
    edge1[cnt].next=head[u];
    head[u]=cnt;
}
stack<int> s;
inline void paint(int u){
    s.pop();
    vis[u]=false;
    col[u]=color;
    size[color]++;
}
inline void tarjan(int u){
    int v,i,j,k;
    tim++;
    dfn[u]=low[u]=tim;
    s.push(u);
    vis[u]=true;
    for(i=head[u];i;i=edge1[i].next){
        v=edge1[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],low[v]);
    }
    if(low[u]==dfn[u]){
        color++;
        while(s.top()!=u){
            paint(s.top());
        }
        paint(u);
    }
    return;
}//到这都是强连通分量的板子，毫无亮点
//edge2用来记录缩点完的正向边，edge3用来记录缩点完的反向边
struct Edge2{
    int from,to,dis,next;
}edge2[1000010];
struct Edge3{
    int from,to,dis,next;
}edge3[1000010];
inline void addedge2(int u,int v){
    cnt++;
    edge2[cnt].from=u;
    edge2[cnt].to=v;
    edge2[cnt].dis=size[v];
    edge2[cnt].next=head[u];
    head[u]=cnt;
}
inline void addedge3(int u,int v){
    cntt++;
    edge3[cntt].from=u;
    edge3[cntt].to=v;
    edge3[cntt].dis=size[v];
    edge3[cntt].next=head1[u];
    head1[u]=cntt;
}
struct node{
    int num,dis,use_time;//现在点的编号，到目前点的距离，是否用过逆向
    friend bool operator < (node a,node b){
        return a.dis>b.dis;
    }
};
priority_queue<node> q;//这个题在缩点后可以转换为一个求dag上最长路的问题
inline void dij(int s){
    int u,v,w,i,j,k,use_tim;
    q.push((node){s,0,0});
    while(!q.empty()){
        node front=q.top();
        q.pop();
        u=front.num;
        use_tim=front.use_time;
        if(front.dis>dis[u][front.use_time]) continue;
        for(i=head[u];i;i=edge2[i].next){//这个是正向边的
            v=edge2[i].to;
            w=edge2[i].dis;
            if(debug) cout<<u<<" "<<v<<" "<<w<<endl;
            if(dis[v][use_tim]<dis[u][use_tim]+w){
                dis[v][use_tim]=dis[u][use_tim]+w;
                q.push((node){v,dis[v][use_tim],use_tim});
            }
        }
        if(!use_tim){//如果我还没逆向走过，可以考虑用或不用
            for(i=head1[u];i;i=edge3[i].next){
                v=edge3[i].to;
                w=edge3[i].dis;
                if(dis[v][1]<dis[u][0]+w){
                    dis[v][1]=dis[u][0]+w;
                    q.push((node){v,dis[v][1],1});
                }
            }
        }
    }
}
int main(){
    n=read();
    m=read();
    int i,j,k;
    for(i=1;i<=m;i++){
        int x,y;
        x=read();
        y=read();
        addedge1(x,y);
    }
    for(i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    //debug=true;
    if(debug){
        for(i=1;i<=n;i++){
            cout<<col[i]<<" ";
        }
        cout<<endl;
    }
    cnt=0;
    memset(head,0,sizeof(head));
    int u,v,w;
    for(i=1;i<=m;i++){
        u=edge1[i].from;
        v=edge1[i].to;
        if(col[u]==col[v]) continue;
        addedge2(col[u],col[v]);
        addedge3(col[v],col[u]);
    }
    //debug=true;
    if(debug){
        for(i=1;i<=cnt;i++){
            cout<<edge2[i].from<<" "<<edge2[i].to<<" "<<edge2[i].dis<<endl;
        }
        cout<<endl<<endl;
        for(i=1;i<=cnt;i++){
            cout<<edge3[i].from<<" "<<edge3[i].to<<" "<<edge3[i].dis<<endl;
        }
    }
    //debug=true;
    if(debug){
        u=1;
        for(i=head1[u];i;i=edge3[i].next){
            v=edge3[i].to;
            w=edge3[i].dis;
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
        cout<<endl<<endl;
    }
    dij(col[1]);
    //debug=true;
    if(debug){
        for(i=1;i<=color;i++){
            cout<<dis[i][0]<<endl;
        }
    }
    int ans=max(dis[col[1]][1],dis[col[1]][0]);//最后得出答案
    cout<<ans<<endl;//轻松ac（逃
    return 0;
}
