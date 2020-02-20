#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long n,k,m;
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}
bool check(long long x){
  long long re = 0, mlk = 0, now = 0;
  for (int i=0;i<ceil(sqrt(x));i++){
		if (floor((n-re)/x)>m){
	    mlk+=floor((n-re)/x);
	    re+=floor((n-re)/x);
		}
  }
  mlk+=(k-now)*m;
  return mlk>=n;
}
void bs(long long need, long long day, long long least){
  long long le = 0, ri = 1e12;
  while(le!=ri-1){
    long long mid = (le+ri)/2;
    if (check(mid)) le = mid;
    else ri = mid;
  }
  if (check(ri)) cout << ri;
  else cout << le;
}



int main(){
  setIO("loan");
  cin >> n >> k >>m;
  bs(n,k,m);

}
