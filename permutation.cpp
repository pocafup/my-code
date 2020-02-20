#include <iostream>
using namespace std;
int main(){
  long long a,b; cin >> a >> b;
  long long ans = 1;
  for (long long i=a;i>(a-b);i--) ans *= i;
  cout << ans;
}
