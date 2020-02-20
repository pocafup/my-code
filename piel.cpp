#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int c[a][b];
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> c[i][j];
    }
  }
  int z = 1;
  for (int i=a-2;i>=0;i--){
    for (int j=b-1;j>b-z-1;j--){
      c[i][j] = 0;
    }
    z++;
  }
  for (int j=b-1;j>=0;j--){
    for (int i=a-1;i>=0;i--){
      int e,f,g;
      if (i-1>=0 && j+1<b){
        e = c[i-1][j+1];
      }else{
        e = 0;
      }
      if (j+1<b){
        f = c[i][j+1];
      }else{
        f = 0;
      }
      if (j+1<b && i+1<a){
        g = c[i+1][j+1];
      }else{
        g = 0;
      }
      // if (i == 1 && j == 5){
      //   cout << e << " " << f << " " << g << endl;
      // }
      // if (i == 1 && j == 5){
      //   cout << c[i][j] << endl;
      // }
      c[i][j] += max(max(e,f), g);

    }
  }


  // for (int i=0;i<a;i++){
  //
  //   for (int j=0;j<b;j++){
  //     cout << c[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << c[0][0];
}
