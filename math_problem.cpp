#include <iostream>
using namespace std;
int main(){
  long long ans = 0;
  for (int i=1;i<=60000;i++) if (i%4==0 || i%5==0 || i%6==0) ans += i;
  cout << ans;
}
