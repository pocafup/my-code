#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
  int a; cin >> a;
  for (int i=1;i<=a;i++){
    long long b; cin >> b;
    cout << "Person #" << i << ": $" << floor(b/2) << endl;
  }
}
