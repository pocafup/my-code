#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a;
  cin >> a;
  int b[3];
  int c[3];
  int ans = 0;
  int vary[5] = {-2,-1,0,1,2};
  for (int i=0;i<3;i++){
    cin >> b[i];
  }

  for (int i=0;i<3;i++){
    cin >> c[i];
  }
  for (int i=1;i<a+1;i++){
    for (int j=1;j<a+1;j++){
      for (int k=1;k<a+1;k++){
        bool mas = false;
        bool far = false;
        int count2 = 0;
        int count1 = 0;
        for (int l=0;l<5;l++){
          if (i+vary[l] <= 0){
            if(i+vary[l]+a == b[0]){
              far = true;
            }
          }
          if (i+vary[l] > a){
            if(i+vary[l]-a == b[0]){
              far = true;
            }
          }
          if(i+vary[l] == b[0]){
            far = true;
          }
        }
        if (far){
          far = false;
          count1++;
        }
        for (int l=0;l<5;l++){
          if (j+vary[l] <= 0){
            if(j+vary[l]+a == b[1]){
              far = true;
            }
          }
          if (j+vary[l] > a){
            if(j+vary[l]-a == b[1]){
              far = true;
            }
          }
          if(j+vary[l] == b[1]){
            far = true;
          }
        }
        if (far){
          far = false;
          count1++;
        }
        for (int l=0;l<5;l++){
          if (k+vary[l] <= 0){
            if(k+vary[l]+a == b[2]){
              far = true;
            }
          }
          if (k+vary[l] > a){
            if(k+vary[l]-a == b[2]){
              far = true;
            }
          }
          if(k+vary[l] == b[2]){
            far = true;
          }
        }
        if (far){
          far = false;
          count1++;
        }

        for (int l=0;l<5;l++){
          if (i+vary[l] <= 0){
            if(i+vary[l]+a == c[0]){
              mas = true;
            }
          }
          if (i+vary[l] > a){
            if(i+vary[l]-a == c[0]){
              mas = true;
            }
          }
          if(i+vary[l] == c[0]){
            mas = true;
          }
        }
        if (mas){
          mas = false;
          count2 ++;
        }
        for (int l=0;l<5;l++){
          if (j+vary[l] <= 0){
            if(j+vary[l]+a == c[1]){
              mas = true;
            }
          }
          if (j+vary[l] > a){
            if(j+vary[l]-a == c[1]){
              mas = true;
            }
          }
          if(j+vary[l] == c[1]){
            mas = true;
          }
        }
        if (mas){
          mas = false;
          count2++;
        }
        for (int l=0;l<5;l++){
          if (k+vary[l] <= 0){
            if(k+vary[l]+a == c[2]){
              mas = true;
            }
          }
          if (k+vary[l] > a){
            if(k+vary[l]-a == c[2]){
              mas = true;
            }
          }
          if(k+vary[l] == c[2] && k+vary[l] > 0){
            mas = true;
          }
        }
        if (mas){
          mas = false;
          count2 ++;
        }

        if (count1 >2 or count2 > 2){
          ans ++;
        }
      }
    }
  }
  cout << ans  ;
}
