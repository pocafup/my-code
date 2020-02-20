#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char s[2010];
#define INF 2*1e8;
int n,m,dp[3010][3010],val[3010];
int main(){
    cin >> n >> m;
    for (int i=1;i<=m;i++) cin >> s[i];
    //for (int i=0;i<m;i++) cout << s[i]  << " ";
    int a,b;
    char k;
    for(int i=1;i<=n;++i){
        cin >> k >> a >> b;
        val[k-'a']=min(a,b);
    }
    for (int i=0;i<=3000;i++){
      for (int j=0;j<=3000;j++){
        dp[i][j] = 2*1e8;
      }
    }
    for(int i=1;i<=m;++i){
        dp[i][i]=0;
        if(s[i]==s[i+1])dp[i][i+1]=0;
    }
    for(int l=0;l<=m;++l)
        for(int i=1;i<=m;++i){
            int j=i+l;
            a=s[i-1]-'a';
            b=s[j+1]-'a';
            if(a==b)dp[i-1][j+1]=min(dp[i-1][j+1],dp[i][j]);    //玄学
            dp[i-1][j]=min(dp[i-1][j],dp[i][j]+val[a]);//D P
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+val[b]);//方程
        }

    for(int i=0;i<=m;i++){
      for (int j=0;j<=m;j++){
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
}
