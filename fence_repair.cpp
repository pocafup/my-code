#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
long long pos[20001];
long long ans = 0;
vector<long long> vec;

int main(){
  long long a; cin >> a;
  priority_queue<long long> pq;

  for (long long i=0;i<a;i++) {cin >> pos[i];pq.push(-pos[i]);}

  while(pq.size()>1){
    long long temp = 0;
    temp-=pq.top();pq.pop();
    temp-=pq.top();pq.pop();
    ans += temp;
    pq.push(-temp);
  }
  cout << ans;
}
