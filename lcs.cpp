#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  string a,b;
  getline(cin,a);
  getline(cin,b);
  int c[a.size()], d[b.size()];
  for (int i=0;i<a.size();i++){
    c[i] = int(a[i])-48;
    d[i] = int(b[i])-48;
  }
}
