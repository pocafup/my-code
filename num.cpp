#include <iostream>
#include <cmath>
using namespace std;
int a,b;
int k = 0;
int c = 1;

bool boll = false;
int main(){
  cin >> a >> b;
  while (k != a){
    int digit[1000];
    int bn = 1;
    int re = c;
    digit[0] = re%10;
    while (re >= 10){
      re = re/10;
      digit[bn] = re%10;
      bn ++;
    }
    for (int i = 0;i<bn;i++){
      if(digit[i] == b){
        boll = true;
      }
    }
    if(boll == false){
      k++;
    }else{
      boll = false;
    }
    c ++;
    }
    cout << c-1;
}
