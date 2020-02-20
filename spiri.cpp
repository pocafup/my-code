#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a; cin >> a;
  int b[a][a];
  memset(b,0,sizeof(b));
  for (int i=0;i<a;i++){
    b[i][0] = 1;
  }
  int n = a-1;
  bool down = true;
  int x = 0;
  int y = 0;
  while (n>0){
    if (down){
      if (n == 1){
        cout << n << " " << x <<" "<< y << endl;
      }
      for (int i=y+1;i<=y+n;i++){
        b[x][i] = 1;
      }
      y += n;
      for (int i=x+1;i<=x+n;i++){
        b[i][y] = 1;
      }
      x += n;
      if (n <= 2){
        b[x][y] = 0;
      }
      down = false;
    }else{
      for(int i=y-1;i>y-n-1;i--){
        b[x][i] = 1;
      }
      y -= n;
      for (int i=x-1;i>x-n-1;i--){
        b[i][y] = 1;
      }
      x -= n;
      down = true;
      if (n <= 2){
        b[x][y] = 0;
      }
    }
    n -= 2;
    cout << n << endl;
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (b[j][i]){
        cout << "*";
      }else{
        cout << " ";
      }
    }
    cout << endl;
  }
}
