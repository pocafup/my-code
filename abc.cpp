/*
ID:dx424391
PROG: teleport
LANG:C++
*/
#include <cstring>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(){
  ofstream fout ("teleport.out");
  ifstream fin ("teleport.in");
  int a[101];
  memset(a,0,sizeof(a));
  int i = 0;
  while(cin>>a[i]){
    i++;
  }
  int mini = 32760;
  int ee;
  for (int j=0;j<i;j++){
    cout << "aa";

    if (j==0){
      ee = i-1;
    }else{
      ee = j-1;
    }
    int temp = a[j]+ a[ee], re = j;
    bool t = true;
    while(t){
      if (ee==0){
        ee = i-1;
      }else{
        ee = j-1;
      }
      if (ee!=re){
        temp += a[ee];
      }else{
        t = false;
      }
    }
    if (temp<mini){
      mini = temp;
    }
  }

  cout << mini;
  return 0;
}
