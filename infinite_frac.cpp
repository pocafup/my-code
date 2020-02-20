#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
int main(){
  int a; cin >> a;
  for (int i=1;i<=a;i++){
    int b,c; cin >> b >> c;
    cout << "Fraction #" << i << ": ";
    if (b+c>=0) printf("%.2lf",sqrt(b+c));
    else cout << "DNE";
    cout << endl;
  }
}
