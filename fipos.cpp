#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a; cin >> a;
  int b[a], c[a];
  for (int i=0;i<a;i++){
    int d; cin >> d;
    b[i] = d;
    c[i] = d;
  }
  sort(c,c+a);
  int pos = 0;
  int fin = a-1;
  int go = 0;
  int count = 0;
  // for (int i=0;i<a;i++){
  //   cout << c[i] << " ";
  // }
  // cout << endl;
  int n = 0;
  while (!n){
    n = true;
    for (int i=0;i<a;i++){
      for (int j=i+1;j<a;j++){
        if (b[i] == c[j] && c[i] == b[j] && b[i] != b[j]){
          // for (int z=0;z<a;z++){
          //   cout << b[z] << " ";
          // }
          // cout << endl;
          int temp = b[i];
          b[i] = b[j];
          b[j] = temp;
          count ++;
          n = false;
        }
      }
    }
  }

  for (int i=a-1;i>=0;i--){
    for (int j=0;j<=i;j++){
      if ((b[j] == c[i]) && b[i] != b[j] && b[i]!= c[i]){
        // for (int z=0;z<a;z++){
        //   cout << b[z] << " ";
        // }
        // cout << endl;
        int temp = b[i];
        b[i] = b[j];
        b[j] = temp;
        count ++;
      }
    }
  }

  cout << count;
}
