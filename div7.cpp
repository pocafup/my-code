#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a;
  int maxi = 0;
  cin >> a;
  int b[a];
  int d = a;
  for (int i=0;i<a;i++){
    int c;
    cin >> c;
    if (i>0){
      b[i] = (b[i-1]+c)%7;
    }else{
      b[i] = c%7;
    }
  }
  bool done = false;
  while(!done && d!= 1){
    for (int i=0;i<a-d+1;i++){
      if (b[i]==b[i+d]){
        maxi = d;
        done = true;
      }
    }
    d--;
  }
  cout << maxi;
}
