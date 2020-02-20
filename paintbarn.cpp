/*
ID:dx424391
PROG: paintbarn
LANG:C++
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int main(){
  ofstream fout("paintbarn.out");
  ifstream fin("paintbarn.in");
  int a,b; fin >> a >> b;
  int c[1000][1000];
  memset(c,0,sizeof(c));
  int x1,y1,x2,y2;
  for (int k=0;k<a;k++){
    fin >> x1 >> y1 >> x2 >> y2;
    int temp1 = max(x1,x2);
    int temp2 = max(y1,y2);
    x1 = min(x1,x2);
    y1 = min(y1,y2);
    for (int i=x1;i<temp1;i++){
      for (int j=y1;j<temp2;j++){
        c[i][j]++;
      }
    }

  }
  int count = 0;
  for (int i=0;i<1000;i++){
    for (int j=0;j<1000;j++){
      if (c[i][j] == b){
        count ++;
      }
    }
  }

  fout << count;
}
