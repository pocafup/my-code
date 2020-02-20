
#include <iostream>
#include <algorithm>

using namespace std;
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
int main(){
  int a,b; cin >> a >> b;

}
