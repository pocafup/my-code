#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
  string a = "COW";
  a.insert(0,"W");
  for (int i=0;i<a.size();i++){
    cout << a[i];
  }
}
