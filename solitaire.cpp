#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int a;
  cin >> a;
  int b[a][a];
  for (int i=a-1;i>=0;i--){
    for (int j=0;j<a;j++){
      string a;
      cin >> a;
      if(a[0] == 'A'){
        b[i][j] = 1;
      }else if(a[0] == 'K'){
        b[i][j] = 13;
      }else if(a[0] == 'Q'){
        b[i][j] = 12;
      }else if(a[0] == 'J'){
        b[i][j] = 11;
      }else if(a[0] == 'T'){
        b[i][j] = 10;
      }else{
        b[i][j] = int(a[0]-48);
      }
    }
  }
  for (int i=1;i<a;i++){
    b[i][0] = b[i-1][0]+b[i][0];
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (int i=0;i<a;i++){
    for (int j=1;j<a;j++){
      if (i-1>=0 && j-1>=0){
        b[i][j] = max(b[i-1][j],b[i][j-1])+b[i][j];
      }else if(i-1>0){
        b[i][j] = b[i][j]+ b[i-1][j];
      }else{
        b[i][j] = b[i][j]+ b[i][j-1];
      }
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout << b[i][j] << " ";
    }
    cout << endl;
  }


}
