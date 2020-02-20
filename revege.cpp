/*
ID:dx424391
PROG: revegetate
LANG:C++
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <queue>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int main(){
  ofstream cout("revegetate.out");
  ifstream cin("revegetate.in");
  int a,b; cin >> a >> b;
  int index[a];
  memset(index,0,sizeof(index));
  vector<int> aa;
  int pt = 1;
  for (int i=0;i<b;i++){
    char d;
    int e,f;
    cin >> d >> e >> f;
    e--;
    f--;
    if(index[e] == 0 && index[f] == 0){
      index[e] = pt;
      index[f] = pt;
      pt++;
    }else if (index[e] == 0 && index[f] != 0){
      index[e] = index[f];
    }else if (index[e] !=0 && index[f] == 0){
      index[f] = index[e];
    }else{
      index[f] = min(index[e],index[f]);
      index[e] = index[f];
      pt--;
    }
  }
  int count = 0;
  for (int i=0;i<a;i++){
    if(index[i] == 0){
      count++;
    }
  }
  int num;
  //cout << pt-1 << " " << count << endl;
  if (count>0){
    num = pow(pt-1,2)*pow(count,2)*4;

  }else{
    num = pow(pt-1,2)*2;
  }
  vector<int> bin;
  while (num > 0)
    {
        bin.push_back(num%2);
        num /= 2;
    }
  for (int i=bin.size()-1;i>=0;i--){
    cout << bin[i];
  }
}
