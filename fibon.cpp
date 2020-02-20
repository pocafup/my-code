#include <iostream>
#include <algorithm>

using namespace std;
int fib[100001];

int main(){
  int a; cin >> a;
  fib[0] = 1;
  fib[1] = 1;
  for (int i=2;i<100000;i++) fib[i] = fib[i-1]+fib[i-2];
  for (int i=0;i<a;i++){
    int b; cin >> b;
    cout << fib[i] << endl;
  }
}
