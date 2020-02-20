#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  vector<int> e;
  int z[a];
  for (int i=0;i<a;i++){
    cin >> z[i];
  }
  for (int i=0;i<a;i++){
    e.push_back(z[i]);
  }
  cout << "aa";
  int maxi = 0;

  sort(e.begin(),e.end());

  while(!e.empty()){
    if (e.size()>=c){
      maxi = max(e[c-1]-e[0],maxi);
      e.erase(e.begin()+1);
    }else{
      maxi = max(e[e.size()-1]-e[0],maxi);
      e.erase(e.begin()+e.size());
    }
  }
  cout << maxi;
}
