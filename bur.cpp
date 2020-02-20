#include <iostream>
#include <algorithm>

using namespace std;

char po1[501][51];
char po2[501][51];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++)
    for (int j=0;j<b;j++)
      cin >> po1[i][j];
  for (int i=0;i<a;i++)
    for (int j=0;j<b;j++)
      cin >> po2[i][j];

  int ans = 0;
  for (int i=0;i<b;i++){
    for (int j=i+1;j<b;j++){
      for (int k=j+1;k<b;k++){
        bool n = true;
        for (int l=0;l<a;l++){
          for (int ll = 0;ll<a;ll++){
            if (po1[l][i] == po2[ll][i] && po1[l][j] == po2[ll][j] && po1[l][k] == po2[ll][k]){
              n = false;
            }
          }

        }
        if (n) {
          cout << i << " " << j << " " << k << endl;
          ans++;
        }
      }
    }
  }
  cout << ans;
}
