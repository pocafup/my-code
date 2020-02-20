#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#define mod 1e9+7;
int main(){
  string a,b;
  cin >> a >> b;
  vector<char> vec;
  int pos = 0;
  int sum1 = 0,sum2 = 0;
  for (int i=0;i<b.size();i++){
    sum1 = (sum1+(int)a[i]-'a'*pow(2,i))%mod;
    sum2 = (sum2+(int)b[i]-'b'*pow(2,i))%mod;
  }
  while(pos!=a.size()-b.size()+1){
    if (sum1!=sum2){
      pos++;
      vec.push_back(a[pos]);
      sum1 -=
    }
  }
}
