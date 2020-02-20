#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  long long c[a+1][2];
  long long temp[a+1];
  memset(c,0,sizeof(c));
  for (int i=1;i<a+1;i++){
    c[i][0] = 1;
  }
  for (int i=1;i<a+1;i++){
    temp[i] = i;
  }
  int bee = 1;
  while(bee){
    bee = false;
    for (int i=1;i<a+1;i++){
      c[i][1] = max(c[i][1],c[i][0])%5000011;
      if (i>=b+1){

        c[i][1] = max(c[i][1],temp+1)%5000011;
      }
    }
    for (int i=1;i<a+1;i++){
      if (c[i][1] != c[i][0]){
        bee = true;
      }
    }
    // for (int j=0;j<a+1;j++){
    //   cout << c[j][0] << " ";
    // }
    // cout << endl;
    // for (int j=0;j<a+1;j++){
    //   cout << c[j][1] << " ";
    // }
    // cout << endl;
    for (int j=1;j<a+1;j++){
      temp[j] = temp[j-1]+c[j][1];
    }
    for (int j=0;j<a+1;j++){

      c[j][0] = c[j][1];
      c[j][1] = 0;
    }

  }
  long long maxint = 0;
  for (int i=0;i<a+1;i++){
    maxint = (maxint+(c[i][0]%5000011)) % 5000011;
  }
  cout << maxint+1;

}
