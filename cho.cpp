#include <iostream>
#include <algorithm>

using namespace std;

long long comb(int fir, int sec){
  long long zz = 1;
  for (int i=fir;i>(fir-sec);i--){
    zz*=i;
  }
  cout << zz << endl;
  for (int i=1;i<=sec;i++){
    zz/=i;
  }
  cout << zz << endl;
  return zz;
}

int main(){
  long long a; cin >> a;
  long long b = comb(a-1,3);
  long long c = comb((a/2),3)*4;
  cout<< b-c;

}
