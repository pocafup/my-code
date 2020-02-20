#include <iostream>
#include <algorithm>

using namespace std;

int ch[27][27],maxi = 0;
char grid[51][51];

int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++)
    for (int j=0;j<b;j++)
      cin >> grid[i][j];

  for (int i=0;i<26;i++){
    for (int j=i+1;j<26;j++){
      for (int k=0;k<a;k++){
        for (int l=0;l<b;l++){
          if (int(grid[k][l])-65==i || int(grid[k][l])-65==j){
            ch[i][j]++;
            //cout << i << " " << j << " " << int(grid[i][j])-65 << endl;
          }
        }

      }
      maxi = max(maxi,ch[i][j]);
    }
  }
  cout << maxi;
}
