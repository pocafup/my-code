#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct cow{
  int height,weight,strength;
}mycow[21];
int c,d,e;
cow get_cow(int aa, int bb, int cc){
  cow g;
  g.height = aa;
  g.weight = bb;
  g.strength = cc;
  return g;
}
pair<int,int> dp[(1<<20)];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) {cin >> c >> d >> e; mycow[i] = get_cow(c,d,e);}
  for (int i=0;i<(1<<a);i++) dp[i] = make_pair(0,-1000);
  for (int i=0;(1<<i)<(1<<a);i++) dp[(1<<i)] = make_pair(mycow[i].height,mycow[i].strength);
  for (int i=1;i<(1<<a);i++){
    for (int j=0;(1<<j)<(1<<a);j++){
      int cc = i%(1<<(j+1));
      if (cc<(1<<j)){
        if (dp[i].second-mycow[j].weight>=0){
          dp[i+(1<<j)] = make_pair(dp[i].first+mycow[j].height,max(dp[i+(1<<j)].second,min(dp[i].second-mycow[j].weight,mycow[j].strength)));
        }
      }
    }
    // cout << endl;
  }
  int ans = 0;
  for (int i=0;i<(1<<a);i++){if (dp[i].second>0 && dp[i].first>=b) ans = max(dp[i].second,ans);}
  if(ans ==0) cout << "Mark is too tall";
  else cout << ans;
}
