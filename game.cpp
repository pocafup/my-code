#include <iostream>
#include <algorithm>

using namespace std;

bool sorted(long long a, long long b){
  return a<b;
}
int main(){
  long long a; cin >> a;
  pair<long long,long long> q[a];

  for (long long i=0;i<a;i++){
    long long c,d; cin >> c >> d;
    q[i].first = c > d ? c : d;
    q[i].second = c < d ? c : d;
  }

  long long ans = 0;
  for (long long i=0;i<a;i++){
    for (long long j=0;j<a;j++){
        if (i!= j){
          if (q[i].first == q[j].first ||
              q[i].second == q[j].first ||
              q[i].first == q[j].second ||
              q[i].second == q[j].second){ ans++;
          }else if (q[i].first<q[j].first && q[i].second>q[j].second) ans++;
        }
    }
  }
  cout << ans;
}
