/*
ID:dx424391
PROG: blist
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

int main(){
  ofstream fout ("blist.out");
  ifstream fin ("blist.in");
  int a;
  fin >> a;
  int b[1000];
  int c,d,e;
  memset(b,0,sizeof(b));
  for (int i=0;i<a;i++){
    fin >> c >> d >> e;
    for (int i=c;i<d;i++){
      b[i] += e;
    }
  }
  int max = 0;
  for (int i=0;i<1000;i++){
    if (b[i]>max){
      max = b[i];
    }
  }
  fout << max;
}
