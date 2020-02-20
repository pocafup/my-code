#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a; cin >> a;
  char b; cin >> b;
  for (int i=0;i<a;i++){
    cout << b;
  }
  cout << endl;
  for (int i=0;i<a-2;i++){
    cout << b;
    for (int j=0;j<a-2;j++){
      cout << " ";
    }
    cout << b << endl;
  }
  for (int i=0;i<a;i++){
    cout << b;
  }
}
