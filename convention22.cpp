/*
ID:dx424391
PROG: convention2
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main(){
  ofstream fout("convention2.out");
  ifstream fin ("convention2.in");
  int a;
  fin >> a;
  vector< pair<long long,long long> > b;
  long long mini = 100000000000;
  long long mini2;
  int re,re2;
  long long wait = 0;
  long long now = 0;
  for (int i=0;i<a;i++){
    pair<int,int> c;
    fin >> c.first >> c.second;
    b.push_back(c);
    if (b[i].first<mini){
      mini = b[i].first;
      re = i;
    }
  }
  now = mini+b[re].second;
  b.erase(b.begin()+re);
  bool n;
  while (!b.empty()){
    n = true;
    //fout << now << endl;
    for (int i=0;i<b.size();i++){
      if (b[i].first<now){
        wait = max(wait,now-b[i].first);
        now += b[i].second;

        b.erase(b.begin()+i);
        n = false;
        break;
      }
    }
    if (n){
      for (int i=0;i<b.size();i++){
        mini2 = 100000000000;
        if (b[i].first<mini2){
          mini2 = b[i].first;
          re2 = i;
        }
      }
      now = mini2+b[re2].second;
      b.erase(b.begin()+re2);
    }
  }
  fout << wait;



}
