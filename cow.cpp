#include <iostream>

using namespace std;

int main(){
  int a;
  cin >> a;
  char b[a];
  int c=0 , co=0, cow=0;
  for (int i=0;i<a;i++){
    cin >> b[i];
  }
  for (int i=0;i<a;i++){
    if (b[i] == 'C'){
      c ++;
    }else if (b[i] == 'O'){
      co += c;
    }else{
      cow += co;
    }
  }
  cout << cow;
}
