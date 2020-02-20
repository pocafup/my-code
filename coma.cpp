#include <iostream>
#include <cstring>

using namespace std;

int main(){
  int a; cin >> a;
  int b[a][a];
  memset(b,0,sizeof(b));
  for (int i=0;i<a;i++){
    b[i][0] = 1;
  }
  int n = a-1;
  bool down = false;
  int count = 0;
  int pos = 0;
  while (n>2){
    if (down){
      for (int i=0;i<n;i++){
        b[count][i+1] = 1;
      }
      pos += n;
      for (int i=0;i<n;i++){
        b[i+1][pos] = 1;
      }
      count += n;
      down = false;
      n -= 2;

    }else{
      for (int i=n;i>0;i--){
        b[count][i-1] = 1;
      }
      pos -= n;
      for (int i=n;i>0;i--){
        b[i-1][pos] = 1;
      }
      n -= 2;
      down = true;
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout << b[j][i];
    }
    cout << endl;
  }

}
