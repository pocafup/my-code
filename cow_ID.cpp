#include <iostream>
#include <algorithm>

using namespace std;

long long fact(long long n){
    if(n==0) return 1;
    return n*fact(n-1);
}

long long comb(long long n,long long r)
{
 long long  fac1 = 1,fac2=1,fac;
 for(long long i=r;i>=1;i--,n--)
    {
        fac1 = fac1 * n;
        if(fac1%i==0)
            fac1 = fac1/i;
        else
            fac2 = fac2 * i;
    }
 fac = fac1/fac2;
 return fac;
}

long long fac[101];
int main(){
  long long a,b; cin >> a >> b;
  long long zeros = 0;
  fac[1] = 1;
  fac[0] = 1;
  for (long long i=2;i<101;i++) fac[i] = fac[i-1]*2;
  while(a>comb(zeros+b-1,b-1)){
    a-=comb(zeros+b-1,b-1);
    zeros++;
    //cout << a << " " << comb(zeros+b-1,b-1) << endl;
  }
  //cout << zeros << " " << a <<  endl;
  cout << 1;
  for (long long i=b-2+zeros;i>=0;i--){
    if (a>=fac[i]){
      a-=fac[i];
      cout << 1;
      continue;
    }
    cout << 0;
  }
}
