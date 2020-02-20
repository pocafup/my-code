#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 105

int m,n,gang,cow; //gang 表示当前占场的帮派编号，cow 表示草地上有几头牛
int a[MAXN];

void fight(int &Gang, int &x, int new_cow) //当前占场的帮派号、其奶牛数量和新来的奶牛帮派号
{
    if(x == 0) Gang = new_cow; //如果本来就没牛占领，那就被新来的奶牛占了
    if(Gang == new_cow) x++; //如果新来的奶牛属于当前占场的帮派，那牛数++（包括第一只奶牛）
    else                x--; //否则会有一只原先占场的奶牛去思考人生，牛数--
}

int result(int Gang, int Cow) //表示当前占场的帮派编号和其奶牛数量
{
    int temp[MAXN];
    for(int i=1;i<=n;i++) temp[i] = a[i];
    sort(temp+2,temp+1+n);
    while(temp[n])
    {
        for(int i=n;i>=2;i--) //先暂时忽略 Bissie 的帮派
        {
            fight(Gang,Cow,i);
            temp[i]--;
            if(temp[i] >= temp[i-1]) break; //贪心的将牛数最多的帮派放入草地。
        }
    }
    for(int i=1;i<=temp[1];i++)//最后再将 Bissie 的帮派放入草地
        fight(Gang,Cow,1);
    if(Gang == 1) return Cow; //如果 Bissie 的帮派占领了草地
    else          return 0;
}

int main(void)
{
    cin >> m >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int num = result(0,0);
    if(!num)
    {
        puts("NO");
        return 0;
    }
    cout << "YES\n" << num << "\n";
    for(int i=1;i<=m;i++)
    {
        int temp_gang = gang;
        int temp_cow  = cow;
        for(int j=1;j<=n;j++)
        {
            if(!a[j]) continue;
            a[j]--;
            fight(gang,cow,j); //先把一只奶牛放入草地，然后再判断这种情况是否合法
            if(result(gang,cow) == num)
            {
                cout << j << "\n";
                break; //由于要求字典序最小，所以合法的话就再从头找起
            }
            a[j]++; //不合法的话就赶紧还原状态，找下一个帮派是否合法
            gang = temp_gang;
            cow  = temp_cow;
        }
    }
    return 0;
}
