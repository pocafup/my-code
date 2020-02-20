#include <iostream>
#include <algorithm>

using namespace std;


int main(){
  int a,b,maxi;
  maxi = 0;
  cin >> a >> b;
  int c[a][b];
  int pointx[8] = {-1,0,1,-1,1,-1,0,1};
  int pointy[8] = {-1,-1,-1,0,0,1,1,1};
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> c[i][j];
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      for (int e=0;e<8;e++){
        //cout << "aa" << i << " " << j << " " <<i+pointx[e]<<" " << j+pointy[e]<< endl;
    //    cout << c[i][j] << " " << c[i+pointx[e]][j+pointy[e]] << endl;
        if (i+pointx[e]>=0 && j+pointy[e] >= 0){
          if (c[i][j] == c[i+pointx[e]][j+pointy[e]] && c[i][j]>maxi){
            maxi = c[i][j];
          }
        }
      }

    }

  }
  cout << maxi;
}
