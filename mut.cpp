#include <iostream>
#include <string>

using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  int count = 0;
  for (int i=0;i<a.size();i++){
    for (int j=0;j<b.size();j++){
      count += (int(a[i])-48)*(int(b[j])-48);
    }

  }
  cout << count;
}
