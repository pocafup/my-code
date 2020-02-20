#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  int c[b];
  vector<int> d;
  for (int i=0;i<b;i++){
    cin >> c[i];
  }
  for (int i=0;i<a;i++){
    d.push_back(i+1);
  }
  int n = 0;
  int temp = 0;
  int te = 0;
  while (d.size()>1){

    n+= c[te]-1;
    if (n>=d.size()){
      n = n%d.size();
    }
    d.erase(d.begin()+n);
    te++;
    if (te>=b){
      te = 0;
    }
    // for (int i=0;i<d.size();i++){
    //   cout << d[i] << " ";
    // }
    // cout << c[te];
    // cout << endl;
  }
  cout << d[0];
}
