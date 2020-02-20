/*
ID:dx424391
PROG: herding
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
  ofstream fout("herding.out");
  ifstream fin("herding.in");
  int a; fin >> a;
  vector<int> b;
  for (int i=0;i<a;i++){
    int c;fin >> c;
    b.push_back(c);
  }
  sort(b.begin(),b.end());
  int start = 0, end = 1;
  int maxi = 0, inn = 1;

  while(end<a){
    if (b[end]-b[start]<a){
      end++;
      inn++;
      //fout << inn;
    }else{
      start++;
      inn--;
      if (start == end){
        end++;
        inn++;
      }
    }
    maxi = max(maxi,inn);
  }
  end = a-2;
  int ni = 0;
  while(end>0){
    ni += b[end]-b[end-1]-1;
    end--;
  }
  start = 1;
  int n2 = 0;
  while(start<a-1){
    n2 += b[start+1]-b[start]-1;
    start++;
  }
  fout << a-maxi << endl;
  fout << max(ni,n2);
}
