#include <iostream>
#include <algorithm>

using namespace std;
long long fac(int firs){
  long long zz = 1;
  while(firs>1){
    zz *= firs;
    firs--;
  }
  return zz;
}
long long comb(int fir, int sec){
  long long zz = 1;
  return fac(fir)/fac(sec)/fac((fir-sec));
}

string toBinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ? "0" : "1" )+r; n/=2;}
    return r;
}

int main(){
  long long a,b; cin >> a >> b;
  string binary_a,binary_b;
  binary_a = toBinary(a);
  binary_b = toBinary(b);
  int begin = 0;
  long long ans = 0;
  for (int i=0;i<binary_b.size();i++){
    if (binary_b[i] == 1){
      begin++;
    }
    int cc = binary_b.size()/2+binary_b.size()%2;
    for (int j=cc;j<binary_b.size()-begin;j++){
      cout << binary_b.size()-begin << " " << j << endl;
      ans += comb(binary_b.size()-begin,j);
    }

  }
  cout << ans;
}
