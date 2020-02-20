/*
ID:dx424391
PROG: leftout
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
  ofstream fout("leftout.out");
  ifstream fin("leftout.in");
  int a; fin >> a;
  int c[a][a];
  int count_r = 0;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      char d; fin >> d;
      if (d == 'R'){
        c[i][j] = 1;
        count_r++;
      }else{
        c[i][j] = 0;
      }
    }
  }
  int run_time = 10;
  int run = 0;
  while(count_r>1 && run<run_time){
    run++;

    for (int i=0;i<a;i++){
      int temp = 0;
      for (int j=0;j<a;j++){
        if (c[i][j] == 1){
          temp++;
          //fout << i << " " << j << " " << c[i][j] << " " << temp << endl;
        }
      }
      //fout << temp << endl;
      if (temp>a/2){
        for (int j=0;j<a;j++){
          c[i][j] = (c[i][j]+1)%2;
          if (c[i][j]==1){
            count_r++;
          }else{
            count_r--;
          }
        }
        //fout << count_r << endl;
      }
    }
    // for (int i=0;i<a;i++){
    //   for (int j=0;j<a;j++){
    //     fout << c[i][j];
    //   }
    //   fout << endl;
    // }
    for (int i=0;i<a;i++){
      int temp = 0;
      for (int j=0;j<a;j++){
        if (c[j][i] == 1){
          temp++;
        }
      }
      if (temp>a/2){
        for (int j=0;j<a;j++){
          c[j][i] = (c[j][i]+1)%2;
          if (c[j][i]==1){
            count_r++;
          }else{
            count_r--;
          }
        }

      }
    }
  }
  bool out = true;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (c[i][j] == 1){
        fout << i+1 << " " << j+1;
        out = false;
        break;
      }
    }
  }
  if (out){
    fout << -1;
  }
}
