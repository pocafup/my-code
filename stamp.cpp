#include <iostream>
#include <cstring>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  int q[b];
  int maxi = 0;
  for (int i=0;i<b;i++){
    cin >> q[i];
    maxi = max(maxi,q[i]);
  }
  int maxint = 0;
  int c[a*maxi+1][2];
  memset(c,0,sizeof(c));
  c[0][0] = 0;

  for (int k=0;k<b;k++){
    for (int i=1;i<a*maxi+1;i++){
      c[i][1] = 1000000;
      c[i][1] = min(c[i][1],c[i-1][1]+1);
      if (c[i][0] != 0){
        c[i][1] = min(c[i][1],c[i][0]);

      }
      if (i>=q[k]){
        c[i][1] = min(c[i][1],c[i-q[k]][1]+1);
      //  c[i][1] = min(c[i][1],c[i-q[k]][1]+1);
      }
    }
    // for (int j=0;j<a*maxi+1;j++){
    //   cout << c[j][0] << " ";
    // }
    // cout << endl;
    // for (int j=0;j<a*maxi+1;j++){
    //   cout << c[j][1] << " ";
    // }
    // cout << endl;
    for (int j=0;j<a*maxi+1;j++){

      c[j][0] = c[j][1];
      c[j][1] = 0;
    }
  }

  for (int i=0;i<a*maxi+1;i++){
    if (c[i][0]<=a ){
      maxint = max(maxint,i);
    }else{
      break;
    }
  }
  cout << maxint;
}
