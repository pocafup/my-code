#include <iostream>
#include <algorithm>

using namespace std;

long long comb(int x, int y){
  long long t = 1;
  if (x==y) return 1;
  for (int i=x;i>y;i--) t*=i;
  cout << t << endl;
  for (int i=1;i<=x-y;i++) t/=i;
  return t;
}

int fac[101];
int main(){
  int a,b; cin >> a >> b;
  int zeros = 0;
  fac[1] = 1;
  fac[0] = 1;
  for (int i=2;i<101;i++) fac[i] = fac[i-1]*2;
  while(a>comb(zeros+b-1,b-1)){
    a-=comb(zeros+b-1,b-1);
    zeros++;
    cout << a << " " << comb(zeros+b-1,b-1) << endl;
  }
  cout << zeros << " " << a <<  endl;
  cout << 1;
  for (int i=b-2+zeros;i>=0;i--){
    if (a>=fac[i]){
      a-=fac[i];
      cout << 1;
      continue;
    }
    cout << 0;
  }
}
