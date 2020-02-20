/*
ID:dx424391
PROG: gift1
LANG:C++
*/
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int np;
char re;
int main(){
  cin >> np;
  int count[np];
  string aa;
  char gifts[np];
  for (int i=0;i<np;i++){
    getline(cin, gifts[i]);
    cout << gifts[i];
  }
  char fir[np];

  for (int i=0;i<np;i++){
    getline(cin,fir[i]);
    int c,d;
    cin >> c >> d;
    cout << c << " " << d << endl;
    for (int j=0;j<d;j++){
      char charac;
      cin >> charac;
      for (int k=0;k<gifts.length();k++){
        if(charac == gifts[k]){

        }
      }
    }
  }
}
