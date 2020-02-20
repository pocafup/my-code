#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,x,y;
int head=0,tail=1;
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
int mp[1001][1001],b[1001][1001];
bool flag=0;
struct sm
{
    int xx,yy;
    int step;
}a[10001];
void bfs(int xxx,int yyy)
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    b[x][y]=1;
    a[1].xx=x;
    a[1].yy=y;
    flag=0;
    head=0,tail=1;
    while(head<tail)
    {
        head++;
        for(int i=1;i<8;i++)
        {
            int x2=a[head].xx+dx[i];
            int y2=a[head].yy+dy[i];
            if(x2>=1&&x2<=n&&y2>=1&&y2<=m&&!b[x2][y2])
            {
                tail++;
                a[tail].xx=x2;
                a[tail].yy=y2;
                a[tail].step=a[head].step+1;
                b[x2][y2]=1;
                if(x2==xxx&&y2==yyy)
                {
                    flag=1;
                    return;
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==x&&j==y)mp[i][j]=0;
            else
            {
                bfs(i,j);
                if(!flag)mp[i][j]=-1;
                else mp[i][j]=a[tail].step;
                //cout<<mp[i][j]<<" ";
            }

        }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<mp[i][j]<<"    ";
        }
        cout<<endl;
    }
    return 0;
}
