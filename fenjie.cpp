#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
int n,yin=0,ans = 0;
bool mp[100005];
bool isPrime(int pos){
  if (pos==2) return true;
  for (int i=2;i<=(floor(sqrt(pos))+1);i++){
    if (pos%i==0) return false;
  }
  return true;
}
int main(){
  cin >> n;
  ans = n;
  int l = n;
  for (int i=2;i<=(ceil(sqrt(l))+1);){
    if (n%i==0) {if (!mp[i])yin++;mp[i] = true;n/=i;}
    else i++;
  }
  yin = max(1,yin);
  if (isPrime(n)) mp[n] = true;
  for (int i=2;i<=1e12;i++){
    if (i!=2 && i%2==0) continue;
    if (mp[i]) continue;
    if (ans>l && yin>=5) {cout << ans; exit(0);}
    if (isPrime(i) && !mp[i]) {ans *= i;yin++;}
  }
}
