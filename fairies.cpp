#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long a,b;
int main(){
  int t; cin >> t;
  for (int i=0;i<t;i++){
    cin >> a >> b;
    long long count = 0;
    if (b<a) swap(a,b);
    for (int j=0;j<64;j++){
      if ((pow(2,j)-1)>=a && (pow(2,j)-1)<=b) count++;
    }
    // cout << count << endl;
    if (count%2) cout << 1 << endl;
    else cout << 2 << endl;
  }

}
/*
2
0 1
2 4
*/
