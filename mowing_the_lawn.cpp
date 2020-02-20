#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
long long pos[100001];
queue<long long> q;
priority_queue<long long> pq;
int main(){
  long long a,b; cin >> a >> b;
  for (long long i=0;i<a;i++) cin >> pos[i];
  long long po = 0;
  long long co = 0;
  while(po<a){
    if (co<=b) q.push(-pos[po]);
    else{
      long long qf = q.front();q.pop();
      q.push(-pos[po]+qf);
    }
    po++;
    co++;
  }
  while(!q.empty()){
    pq.push(q.front());q.pop();
  }
  co = 0;
  long long ans = 0;
  for (int i=0;i<a;i++) ans += pos[i];
//   while(pq.size()){
        ans+= pq.top();
    // pq.pop();
//   }
  cout << ans;
}
