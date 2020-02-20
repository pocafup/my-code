#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main(){
  ifstream cin ("moobuzz.in");
  ofstream cout ("moobuzz.out");
  int n; cin >> n;
  int ans = n/8*15,temp = n%8;
  if (n%8==0){cout << ans-1; return 0;}
  while(temp) temp--;ans++; while (ans%3==0||ans%5==0) ans++;
  if (ans%5==0||ans%5==0) ans++;
  cout << ans;
}
