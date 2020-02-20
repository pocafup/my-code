#include <iostream>
using namespace std;
long long prefix[100001];
int main(){
  long long ans = 1;
  int a; cin >> a;
  prefix[0] = 1;
  for (int i=1;i<100000;i++)prefix[i] = prefix[i-1]*i;
  for (int i=1;i<=a;i++){
    ans *= prefix[i];
  }
  cout << ans;
}
