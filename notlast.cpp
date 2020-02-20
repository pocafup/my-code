/*
ID:dx424391
PROG: notlast
LANG:C++
*/
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <queue>


using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main(){
  ofstream fout ("notlast.out");
  ifstream fin ("notlast.in");
  int a,pos = 0;
  fin >> a;
  pair<string,int> b[a];
  vector<pair<string,int> > c;
  for (int i=0;i<a;i++){
    fin >> b[i].first >> b[i].second;
    if (a==1){
      fout << b[i].first;
    }
    bool n = true;
    for (int j=0;j<c.size();j++){
      if (b[i].first == c[j].first){
        c[j].second += b[i].second;
        n = false;
      }
    }
    if (n){
      pair<string,int> re;
      re.first = b[i].first;
      re.second = b[i].second;
      c.push_back(re);
    }
  }
  int mini = 32760;
  for (int i=0;i<c.size();i++){
    if (c[i].second<mini){
      mini = c[i].second;
    }
  }
  bool z = true;
  while (z){
    z = false;
    for (int i=0;i<c.size();i++){
      if (c[i].second==mini){
        c.erase(c.begin()+i);
        z = true;
      }
    }
  }
  // for (int i=0;i<c.size();i++){
  //   fout << c[i].first << " " <<  c[i].second << endl;
  //
  // }
  if (!c.empty()){
    mini = 32760;
    int res = 0;
    for (int i=0;i<c.size();i++){
      if (c[i].second<mini){
        mini = c[i].second;
        res = i;
      }
    }
    fout << c[res].first;
  }else if(a!= 1){
    fout << "Tie";
  }

}
