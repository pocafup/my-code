/*
ID:dx424391
PROG: hps
LANG:C++
*/
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
  ofstream fout ("hps.out");
  ifstream fin ("hps.in");
  int a;
  fin >> a;
  pair<int,int> b[a];
  int win[2][3] = {{2,3,1},{3,1,2}};
  for (int i=0;i<a;i++){
    fin >> b[i].first >> b[i].second;
  }
  int maxi = 0;
  for (int i=0;i<2;i++){
    int point = 0;
    for (int j=0;j<a;j++){
      if (win[i][b[j].first-1] == b[j].second){
        point++;
      }
    }
    maxi = max(maxi,point);
  }
  fout << maxi;


}
