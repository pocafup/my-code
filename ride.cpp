/*
ID:dx424391
PROG: ride
LANG:C++
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  string aa;
  string bb;


  int c = 1;
  int d = 1;
  getline(fin,aa);
  char a[aa.length()];
  for (int i=0;i<aa.length();i++){
    a[i] = aa[i];
  }
  getline(fin,bb);
  char b[bb.length()];
  for (int i=0;i<bb.length();i++){
    b[i] = bb[i];
  }
  for (int i=0;i<aa.length();i++){
    c = ((int)(a[i])-64)*c;
  }
  cout << endl;
  for (int i=0;i<bb.length();i++){
    d = ((int)(b[i])-64)*d;
  }

  if (d % 47 == c % 47){
    fout << "GO" << endl;
    cout << d%47;
  }else{
    fout << "STAY" << endl;
  }
  return 0;
}
