#include <iostream>
#include <algorithm>

using namespace std;

long long pos[3000005];

int main(){
  long long a,b; cin >> a >> b;
  for (long long i=0;i<b;i++){
    long long c,d,e,f; cin >> c >> d >> e >> f;
    for (long long j=1;j<=d;j++){
      pos[(e*j+f)%a]+=c;
    }
  }
  for (long long i=0;i<a;i++) cout << pos[i] << endl;

  for (long long i=0;i<2;i++){
    for (long long j=0;j<a;j++){
      if(pos[j]>1){

        pos[(j+1)%a]+=pos[j]-1;
        pos[j] = 1;
      }
    }
  }
  for(long long i=0;i<a;i++){
    if (pos[i] == 0) {cout << i;break;}
  }
}
