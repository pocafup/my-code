#include <iostream>
#include <algorithm>

using namespace std;

int a;
int close1(int n1,int n2){
  return (abs(n2-n1)<=2) or ((abs(n2-n1+a)<=2) or (abs(n1-n2+a)<=2));
}
int close(int z1, int z2, int z3, int q1, int q2, int q3,int q4, int q5, int q6){
  return ((close1(z1,q1) && close1(z2,q2) && close1(z3,q3)) or (close1(z1,q4) && close1(z2,q5) && close1(z3,q6)));
}

int main(){
  cin >> a;
  int b1,b2,b3,c1,c2,c3;
  cin >> b1 >> b2 >> b3 >> c1 >> c2 >> c3;
  int count = 0;
  for(int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      for (int k=0;k<a;k++){
        if(close(i,j,k,b1,b2,b3,c1,c2,c3)){
          count++;
        }
      }
    }
  }
  cout << count;
}
