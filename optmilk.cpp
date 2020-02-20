#include <iostream>
#include <algorithm>

using namespace std;
long long n,d;
long long pos[40001];
long long dp[40001];
#define ri register int

template <typename T>inline void redi(T& t)
{
    ri c=getchar();t=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))t=t*10+c-48,c=getchar();
}
template <typename T,typename... Args> inline void redi(T& t, Args&... args)
{
    redi(t);redi(args...);
}

long long solve(int po){
  long long count = 0;
  for (long long i=po;i<=n;i++){
    int times = 0;

    if(i-1<=0) {count = pos[i];dp[i] = pos[i];}
    else if (i-2<=0) {dp[i] = max(dp[i-1],pos[i]);count = max(count,dp[i]);}
    else {
      // dp[i] = max(dp[i-1],dp[i-2]+pos[i]);
      count = max(dp[i-1],dp[i-2]+pos[i]);

      // prev1 = max(dp[i-2],dp[i-2]);
      // prev2 = max(dp[i-1],te+pos[i]);
    }
    dp[i] = count;
  }
  // for (int i=1;i<=n;i++) cout << dp[i] << " ";
  // cout << endl;
  return dp[n];
}
int main(){
  redi(n,d);
  long long ans = 0;
  for (long long i=1;i<=n;i++) redi(pos[i]);
  solve(1);
  for (long long i=0;i<d;i++){
    long long a,b; cin >> a >> b;
    pos[a] = b;
    // cout << solve(a) << endl;
    ans += solve(a);
  }
  cout << ans;
}

// #include <iostream>
// #include <algorithm>
//
// using namespace std;
// long long n,d;
// long long pos[40001];
// long long dp[40001];
// long long solve(int po){
//   long long prev1 = -1, prev2 = -1, count = 0;
//   for (long long i=po;i<=n;i++){
//     // cout << prev1 << " " << prev2 << " " << count << endl;
//     if(i-1<=0) {count = pos[i];prev2 = pos[i];}
//     else if (i-2<=0) {count = max(pos[i],count);prev1 = prev2;prev2 = pos[i];}
//     else {
//       count = max(count,pos[i]+dp[i-2]);
//       // long long te = dp[i-2];
//       prev1 = max(dp[i-2],dp[i-1]);
//       prev2 = max(dp[i-1],dp[i-2]+pos[i]);
//     }
//     dp[i] = count;
//   }
//   return count;
// }
// int main(){
//   cin >> n >> d;
//   long long ans = 0;
//   for (long long i=1;i<=n;i++) cin >> pos[i];
//   solve(1);
//   for (long long i=0;i<d;i++){
//     long long a,b; cin >> a >> b;
//     pos[a] = b;
//     // cout << solve() << endl;
//     ans += solve(a);
//   }
//   cout << ans;
// }


// #include <iostream>
// #include <algorithm>
//
// using namespace std;
// long long n,d;
// long long pos[40001];
// long long dp[40001];
// long long solve(int po){
//   long long prev1 = -1, prev2 = -1, count = 0;
//   for (long long i=po;i<=n;i++){
//     // cout << prev1 << " " << prev2 << " " << count << endl;
//     if(i-1<=0) {count = pos[i];prev2 = pos[i];}
//     else if (i-2<=0) {count = max(pos[i],count);prev1 = prev2;prev2 = pos[i];}
//     else {
//       count = max(count,pos[i]+dp[i-2]);
//       // long long te = dp[i-2];
//       prev1 = max(dp[i-2],dp[i-1]);
//       prev2 = max(dp[i-1],dp[i-2]+pos[i]);
//     }
//     dp[i] = count;
//   }
//   return count;
// }
// int main(){
//   cin >> n >> d;
//   long long ans = 0;
//   for (long long i=1;i<=n;i++) cin >> pos[i];
//   solve(1);
//   for (long long i=0;i<d;i++){
//     long long a,b; cin >> a >> b;
//     pos[a] = b;
//     // cout << solve() << endl;
//     ans += solve(a);
//   }
//   cout << ans;
// }
