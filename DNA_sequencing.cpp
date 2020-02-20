#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  int m,f,ans;
  cin >> m >> f;
  string bull[m];
  string cow[f];

  for (int i=0;i<m;i++){
    cin >> bull[i];
  }
  for (int i=0;i<f;i++){
    cin >> cow[i];
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<f;j++){
      for(int k=0;k<m;k++){
        if (k!=i){
          bool dna = true;
          int space = 0;
          while (dna && space!= 25){
            //cout << bull[k][space] << " " << bull[i][space] << " " << cow[j][space] << endl;
            if(bull[k][space]==bull[i][space] or bull[k][space]==cow[j][space]){
              space ++;
            }else{
              dna = false;
            }
          }
          if(dna){
          //  cout << i+1 << " " << j+1 << " " << k+1 << endl;
            ans ++;
          }
        }
      }
      for(int l=0;l<f;l++){
          if (l!=j){
            bool dna = true;
            int space = 0;
            while (dna && space!= 25){
              if(cow[l][space]==bull[i][space] or cow[l][space] == cow[j][space]){
                space ++;
              }else{
                dna = false;
              }
            }
            if(dna){
            //  cout << i+1 << " " << j+1 << " " << l+1 << " a" <<endl;
              ans ++;
            }
          }
        }
        cout << ans << " ";
        ans = 0;
      }
      cout << endl;
    }
  }
