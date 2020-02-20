#include <iostream>
#include <algorithm>
using namespace std;
int f[1005][10005] = {
{1},
{1, 1},
{1, 2, 1},
{1, 3, 3, 1},
{1, 4, 6, 4, 1},
{1, 5, 10, 10, 5, 1},
{1, 6, 15, 20, 15, 6, 1},
{1, 7, 21, 35, 35, 21, 7, 1},
{1, 8, 28, 56, 70, 56, 28, 8, 1},
{1, 9, 36, 84, 126, 126, 84, 36, 9, 1},
{1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1},
{1, 11, 55, 165, 330, 462, 462, 330, 165, 55, 11, 1}
};

int n,sum;
bool flag = 0;
int ans[1005];
bool vis[105];
void dfs(int now,int nsum){
    if(now == n){
        if(nsum == sum){
            //++tot;
            for(register int i = 0;i<n;++i){
                cout<<ans[i]<<" ";
            }
            exit(0);
        }
        return ;
    }
    for(register int i = 1;i <= n;++i){
        if(!vis[i] && nsum + f[n-1][now] * i <=sum){
            vis[i] = 1;
            ans[now] = i;
            dfs(now+1,nsum + i * f[n-1][now]);
            vis[i] = 0;
        }
    }

}
int main(){
    cin>>n>>sum;
    dfs(0,0);
}
