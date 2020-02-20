#include <iostream>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int c = 0;
  int ln = 0;

  while (ln < a){
    c += 1;
    ln ++;
    for (int i=0;i<b;i++){
      cout << c << " ";
      c++;
    }
    c = ln;
    cout << endl;
  }
}
