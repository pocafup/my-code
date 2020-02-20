#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  string<int> a,b;
  cin >> a >> b;
  //for (int i=0;i<a.length();i++) cout << a[i];
  int ans = 0;
  if (a.length()!=b.length()){
    for (int i=a.length()+1;i<b.length();i++) ans += 9*i;
  }
}
