#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define pp pair<long long,long long>
long long a,b;
long long pos[100001];
long long prefix[100001];
long long dp[100001];
priority_queue<pp> pq;
int main(){
  cin >> a >> b;
  for (long long i=1;i<=a;i++) {cin >> pos[i]; prefix[i] = prefix[i-1]+pos[i];}
  for (long long i=0;i<=a;i++){
    while (!pq.empty()){
      while(pq.top().second<i-b-1) pq.pop();
      break;
    }
    if (pq.size()>b) dp[i] = prefix[i]+pq.top().first;
    else dp[i] = prefix[i];
    pq.push(make_pair(dp[i]-prefix[i+1],i));

  }
  cout << dp[a];
}
