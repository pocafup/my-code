#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long n,k,m;
long long num[100][100]={0};
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}
int min(long long a, long long b){return a<b?a:b;}
long long bin_search(long long po){
  long long le = 0,ri = min(k,50), krev = k*m, tian = 0;
  while(le!=ri-1){
    // cout << le << " " << ri << endl;

    int mid = (le+ri)/2;
    double re = 0;
    cout << "mid " << mid << endl;
    for (long long i=1;i<=mid;i++){
      // cout << num[mid+1][i] << " ";
      cout << "aim " << num[mid+1][i] << " " << pow(po,(mid-i)) << " " << n << " " << pow(po,i) << endl;
      re += (num[mid+1][i]*pow(po,(mid-i)))*n/pow(po,i) * pow(-1,i+1);
    }
    cout << "re     " << re << endl;
    cout << endl << po << " " << re << endl;
    long long l = floor(re);
    if (l+(mid)*m>=krev) {le = mid; krev = l; tian = mid;}
    else ri = mid;
  }
  return krev+(k-tian)*m;
}
bool check(long long po){
  long long kk = bin_search(po);
  return kk>=n;
}

void bs(long long need, long long day, long long least){
  long long le = 1, ri = 1e12;
  while(le!=ri-1){
    long long mid = (le+ri)/2;
    if (check(mid)) le = mid;
    else ri = mid;
  }
  cout << "rit " << ri << endl;
  if (check(ri)) cout << ri;
  else cout << le;
}

int main(){
  for(int i=1;i<50;i++){
    num[i][0]=1;
    for(int j=1;j<50;j++){
      num[i][j]=num[i-1][j]+num[i-1][j-1];
    }
  }
  // setIO("loan");
  cin >> n >> k >>m;
  bs(n,k,m);

}
