#include <iostream>
#include <algorithm>

using namespace std;

int square(int z){
  return z*z;
}

int main(){
  int a,b;
  cin >> a >> b;
  int c[b][a];
  bool z[b][a];
  memset(z,false,sizeof(z));
  for (int i=0;i<b;i++){
    for (int j=0;j<a;j++){
      c[i][j] = (square(b-i-1))+(square(a/2-j));
    }
  }
  // for (int i=0;i<b;i++){
  //   for (int j=0;j<a;j++){
  //     cout << c[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  //c[b-1][a/2] = 1;
  int re = 1;
  int s = 0;
  for (int k =0;k<10000;k++){
    for (int i=b-1;i>=0;i--){
      for (int j=0;j<a;j++){
        if (c[i][j] == k&&z[i][j] == false){
          c[i][j] = re;
          z[i][j] = true;
          re ++;
        }
      }
    }
  }


  for (int i=0;i<b;i++){
    for (int j=0;j<a;j++){
      cout << c[i][j] << " ";
      if (c[i][j]<10){
        cout << " ";
      }
    }
    cout << endl;
  }
}
