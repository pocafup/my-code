#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  string aa;
  string bb;
  char a[6];
  char b[6];
  int c = 1;
  int d = 1;
  getline(cin,aa);
  for (int i=0;i<aa.length();i++){
    a[i] = aa[i];
  }
  getline(cin,bb);

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
    cout << "GO";
  }else{
    cout << "STAY";
  }
}
