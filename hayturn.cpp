#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<long long,long long> pp;
long long a;
long long pos[700001];
pp dp[700001];
int main(){
  cin >> a;
  for (long long i=0;i<a;i++) cin >> pos[i];
  long long p1=0,p2=0;
  for (long long i=a-1;i>=0;i--){
    long long temp = p2+pos[i];
    if(temp>=p1){
      p2 += pos[i];
      swap(p1,p2);
    }
  }
  if (p1<p2) swap(p1,p2);
  cout << p1 << " " << p2;
}
