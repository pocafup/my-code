#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int t[2000];
int binary[2000][30];
int map[2000][2000][30];
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) {
    cin >> t[i];
    int begin = 0;
    while(t[i]>1){
      binary[i][begin] = t[i]%2;
      t[i] = t[i]/2;
      begin++;
    }
    binary[i][begin] = 1;
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<15;j++){
      int temp = binary[i][j];
      binary[i][j] = binary[i][30-j-1];
      binary[i][30-j-1] = temp;
    }

  }
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<30;j++){
  //     cout << binary[i][j];
  //   }
  //   cout << endl;
  // }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      for (int k=0;k<30;k++){
        if (i!=j){
          if (binary[i][k]==binary[j][k]){
            map[i][j][k] = 0;
          }else{
            map[i][j][k] = 1;
          }

        }
      }
    }
  }
  for(int i=0;i<a;i++){
    for (int j=0;j<a;j++){

    }
  }
}
