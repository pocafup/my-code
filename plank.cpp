#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

long long pos[50001];
multiset<long long> se;
int main(){
  long long a; cin >> a;
  for (long long i=0;i<a;i++) {
    cin >> pos[i];
    se.insert(pos[i]);
  }
  long long ans = 0;

  while(se.size()>1){
    long long temp = 0;
    multiset<long long>::iterator it = se.begin();
    ans+= *it;
    temp+= *it;
    se.erase(se.begin());
    it = se.begin();
    ans+= *it;
    temp+= *it;
    se.erase(se.begin());
    se.insert(temp);
  }
  cout << ans;
}
