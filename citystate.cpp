#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  int a,ans;
  ans = 0;
  cin >> a;
  int b[26][26][26][26];
  memset(b,0,sizeof(b));
  for (int i=0;i<a;i++){
    string c;
    char d,e;
    cin >> d >> e;
    getline(cin,c);
    int re = 0;
    while(c[re] != ' '){
      re++;
    }
  //  cout << c[e+1] << " " << c[e+2] << endl;
    b[int(c[re+1]-65)][int(c[re+2]-65)][int(d-65)][int(e-65)]++;
    //cin >> d;
    //b[static_cast<char>(c[0])][static_cast<char>(c[1])][static_cast<char>(d[0])][static_cast<char>(c[1])]
  }
  for (int i=0;i<26;i++){
    for (int j=0;j<26;j++){
      for (int k=0;k<26;k++){
        for (int l=0;l<26;l++){
          if (b[i][j][k][l] >0 && b[k][l][i][j] > 0){
            if (i==k && j==l){
                continue;
            }else{
                ans += b[i][j][k][l]*b[k][l][i][j];

            }
          }
        }
      }
    }
  }
  cout << ans/2;
}
