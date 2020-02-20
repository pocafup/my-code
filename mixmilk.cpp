/*
ID:dx424391
PROG: mixmilk
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
  ofstream fout ("mixmilk.out");
  ifstream fin ("mixmilk.in");
  int a,b,c,d,e,f;
  fin >> a >> b >> c >> d >> e >> f;
  int temp;
  for (int i=0;i<33;i++){
    if (b+d>c){
      temp = d;
      d = c;
      b = b+temp-c;
    }else{
      d = b+d;
      b = 0;
    }
    if (d+f>e){
      temp = f;
      f = e;
      d = d+temp-e;
    }else{
      f = d+f;
      d = 0;
    }
    if (f+b>a){
      temp = b;
      b = a;
      f = f+temp-a;
    }else{
      b = b+f;
      f = 0;
    }
  }
  if (b+d>c){
    temp = d;
    d = c;
    b = b+temp-c;
  }else{
    d = b+d;
    b = 0;
  }
  fout << b << endl;
  fout << d << endl;
  fout << f << endl;
  return 0;
}
