#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int a,maxi,maxi2;
  maxi = -10000;
  maxi2 = -1000;
  cin >> a;
  int x1[a];
  int x2[a];
  int y1[a];
  int y2[a];
  for (int i=0;i<a;i++){
    x1[i] = i;
    y1[i] = i;
    x2[i] = i;
    y2[i] = a-i-1;
  }
  int e[a][a];
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cin >> e[i][j];
      if (e[i][j] > maxi2){
          maxi2 = e[i][j];
      }
    }
  }


  for (int i=0;i<a;i++){
    int re = 0;
    for (int zz=0;zz<a;zz++){
      re = 0;
      for (int j=zz;j<zz+a;j++){
        if (j<a){
          re += e[i][j];
        }else{
          re += e[i][j-a];
        }
        if (re>maxi){
          maxi = re;
        }
      }
    }


  }
  for (int i=0;i<a;i++){
    int re3 = 0;
    for (int zz=0;zz<a;zz++){
      re3 = 0;
      for (int j=zz;j<zz+a;j++){
        if (j<a){
          re3 += e[j][i];
        }else{
          re3 += e[j-a][i];
        }
        if (re3>maxi){
          maxi = re3;
        }
      }
    }


  }
  // int ff = 0;
  // for (int dd = 0;dd<a;dd++){
  //   for (int i=0;i<a;i++){
  //     int re2 = 0;
  //     for (int j=i;j<a+i;j++){
  //         re2 += e[j][i];
  //     }
  //     if (re2>maxi){
  //       maxi = re2;
  //     }
  //   }
  //   for (int i=0;i<a;i++){
  //     int res = 0;
  //
  //     for (int j=0;j<a;j++){
  //       if (j+1<a){
  //         res += e[x1[j+1]][y1[j+1]];
  //         if(maxi<res){
  //           maxi = res;
  //         }
  //       }else{
  //         res += e[x1[j-a+1]][y1[j-a+1]];
  //         if(maxi<res){
  //           maxi = res;
  //         }
  //       }
  //     }
  //
  //   }
  // }
  int ff = 0;
  for (int bb = 0;bb<a;bb++){
    for (int i=0;i<a;i++){
  //    cout << "   " << i << " i" << endl;
      int re2 = 0;
      int eee = ff;
      for (int j=i;j<i+a;j++){
        // cout << j << " j"<< endl;
        if (j<a && eee<a){
          re2 += e[eee][y1[j]];

          if(maxi<re2){
            maxi = re2;

          }
        }else if (j>=a && eee<a){
          re2 += e[eee][y1[j-a]];

          if(maxi<re2){
            maxi = re2;

          }
        }else if (eee>=a && j<a){
          re2 += e[eee-a][y1[j]];

          if(maxi<re2){
            maxi = re2;
          }
        }else{
          re2 += e[eee-a][y1[j-a]];

          if(maxi<re2){
            maxi = re2;

          }
        }
        eee++;
      }
    }
    ff++;
  }

  int cc = 0;
  for (int bb = 0;bb<a;bb++){
    for (int i=0;i<a;i++){
  //    cout << "   " << i << " i" << endl;
      int res = 0;
      int ee = cc;
      for (int j=i;j<i+a;j++){
        // cout << j << " j"<< endl;
        if (j<a && ee<a){
          res += e[ee][y2[j]];

          if(maxi<res){
            maxi = res;

          }
        }else if (j>=a && ee<a){
          res += e[ee][y2[j-a]];

          if(maxi<res){
            maxi = res;

          }
        }else if (ee>=a && j<a){
          res += e[ee-a][y2[j]];

          if(maxi<res){
            maxi = res;
          }
        }else{
          res += e[ee-a][y2[j-a]];

          if(maxi<res){
            maxi = res;

          }
        }
        ee++;
      }
    }
    cc++;
  }

    if (maxi != 0){
        cout << maxi;
    }else{
        cout << maxi2;
    }
}
