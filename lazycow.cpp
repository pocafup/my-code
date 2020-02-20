#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int pos[401][401];
bool woo[1000][1000];
int prefix[1000][1000];
int main(){
  int a,b; cin >> a >> b;
  int rotate[1000][1000];
  memset(rotate,0,sizeof(rotate));
  for (int i=0;i<a;i++)
    for (int j=0;j<a;j++)
      cin >> pos[i][j];

  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      rotate[j+i][j-i+a-1] = pos[i][j];
      woo[j+i][j-i+a-1] = true;
      prefix[j+i][j-i+a-1] = pos[i][j];
    }
  }
  for (int i=0;i<a*2;i++){
    for (int j=0;j<a*2;j++){
      cout << rotate[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  int y[3] = {-2,-1,0};
  int x[3] = {0,1,2};
  cout << rotate[0][2] << " " << rotate[2][2] << " " << woo[0][2] << endl;
  for (int i=0;i<a*2;i++){
    for(int j=0;j<a*2;j++){
      for (int k=0;k<3;k++){
        if (i+x[k]>=0 && i+x[k]<a*2 && j+y[k]<a*2 && j+y[k]>=0){
          if (woo[i+x[k]][j+y[k]] && woo[i][j]){
            prefix[i][j] += prefix[i+x[k]][j+y[k]];
          }
        }
      }
    }
  }
  for (int i=0;i<a*4;i++){
    for (int j=0;j<a*4;j++){
      cout << prefix[i][j] << " ";
    }
    cout << endl;
  }
}
