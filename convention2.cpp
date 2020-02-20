/*
ID:dx424391
PROG: convention
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main(){
  // ofstream cout("convention.out");
  // ifstream cin ("convention.in");
  int n,m,c;
  cin >> n >> m >> c;
  vector<int> d;
  int v;
  for (int i=0;i<n;i++){
    cin >> v;
    d.push_back(v);
  }
  int maxi = 0;

  sort(d.begin(),d.end());
  while(!d.empty()){
    if (d.size()>=c){
      maxi = max(d[c-1]-d[0],maxi);
      d.erase(d.begin(),d.begin()+c);

    }else{
      maxi = max(d[d.size()-1]-d[0],maxi);
      d.erase(d.begin(),d.begin()+d.size());
    }
  }
  cout << maxi;
}
