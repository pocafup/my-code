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
  ofstream fout("revegetate.out");
  ifstream fin("revegetate.in");
  int a,b; fin >> a >> b;
  vector<int> index[a];
  vector<int> aa;
  queue<int> q;
  vector<pair<int,int> > e;
  int ind[a];
  memset(ind,0,sizeof(ind));

  int pt = 0;
  for (int i=0;i<b;i++){
    char d;
    int e1,f1;

    fin >> d >> e1 >> f1;
    ind[e1-1] = 1;
    ind[f1-1] = 1;
    e.push_back(make_pair(e1,f1));
  }
  while(!e.empty()){
     pt++;
     q.push(e[0].first);
     q.push(e[0].second);
     e.erase(e.begin());
     while(!q.empty()){
       bool aa = true;
       for (int i=0;i<e.size();i++){
         if(e[i].first == q.front()){
           aa = false;
           q.push(e[i].second);
           //fout << e[i].second << "ee" << endl;
           e.erase(e.begin()+i);
         }else if(e[i].second == q.front()){
           aa = false;
           q.push(e[i].first);
           //fout << e[i].first << "ee" << endl;

           e.erase(e.begin()+i);
         }
       }
       if (aa){
         q.pop();

       }
     }
  }
  int count = 0;
  for (int i=0;i<a;i++){
    if(ind[i] == 0){
      count++;
    }
  }
  // fout << pt << endl;
  // fout << count << endl;
  // long long num = 0;
  // if (count >0){
  //   num = pow(2,pt)*pow(2,count);
  // }else{
  //   num = pow(2,pt);
  // }
  // vector<int> bin;
  // while (num > 0)
  //   {
  //       bin.push_back(num%2);
  //       num /= 2;
  //   }
  // for (int i=bin.size()-1;i>=0;i--){
  //   fout << bin[i];
  // }
  fout << 1;
  for (int i=0;i<pt+count;i++){
    fout << 0;
  }
}
