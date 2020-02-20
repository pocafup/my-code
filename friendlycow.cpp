#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a;
  cin >> a;
  int b[a];
  int d[a];
  int f=0,g=0,h=0;
  for (int i=0;i<a;i++){
    cin >> b[i];
  }
  for (int i=0;i<a;i++){
    cin >> d[i];
  }

  int e[a][a];
  memset(e,0,sizeof(e));
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<a;j++){
  //     if(i>0 && j>0 && b[i]-d[j-1] <= 4){
  //       f = max(e[i-1][j-1]+1,e[i-1][j]);
  //     }else if(j>0 && b[i]-d[j] <= 4){
  //       g = e[i][j-1];
  //     }
  //     e[i][j] = max(f,g);
  //     f=0;
  //     g=0;
  //   }
  // }
  for (int i=0;i<a;i++){
    if (abs(b[i]-d[0])<=4){
      e[i][0]++;
    }

  }
  for (int i=1;i<a;i++){
    if (abs(d[i]-b[0])<=4){
      e[0][i]++;
    }
  }
  for (int i=1;i<a;i++){
    for (int j=1;j<a;j++){
      if (abs(b[i]-d[j])<=4){
        e[i][j] = max(max(e[i-1][j],e[i][j-1]),e[i-1][j-1]+1);
      }else{
        e[i][j] = max(max(e[i-1][j],e[i][j-1]),e[i-1][j-1]);
      }
    }
  }
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<a;j++){
  //     cout << e[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << e[a-1][a-1];
}
