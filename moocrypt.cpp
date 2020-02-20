#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
  int a,b;
  int maxi = 0;
  cin >> a >> b;
  string c[a];
  cin.ignore();
  int alpha[26][26];
  memset(alpha,0,sizeof(alpha));
  for (int i=0;i<a;i++){
    getline(cin,c[i]);
    cout << c[i] << endl;
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b-1;j++){
      cout << int(c[i][j+1]-65) << " " << int(c[i][j]-65) << " " << i << " " << j << endl;

      if (c[i][j] == c[i][j+1]){
        if (j-1 >= 0){
          if (c[i][j-1] != c[i][j]){
             alpha[int(c[i][j-1]-65)][int(c[i][j]-65)] ++;
             cout << int(c[i][j-1]-65) << " " << int(c[i][j]-65) << " eee " << i << " " << j-1 << " " << i << " " << j << endl;
          }
        }
        if (j+2 < b){
          if (c[i][j+2] != c[i][j]){
             alpha[int(c[i][j+2]-65)][int(c[i][j]-65)] ++;
             cout << int(c[i][j+2]-65) << " " << int(c[i][j]-65) << " fff " << i << " " << j+2 << " " << i << " " << j << endl;
          }
        }
      }
    }

  }
  for (int i=0;i<b;i++){
    for (int j=0;j<a-1;j++){

      if (c[j][i] == c[j+1][i]){
        if (j-1 >= 0){
          if (c[j-1][i] != c[j][i]){
             alpha[int(c[j-1][i]-65)][int(c[j][i]-65)] ++;
             cout << int(c[j-1][i]-65) << " " << int(c[j][i]-65) << " eee " << j-1 << " " << i << " " << j << " " << i<< endl;
          }
        }
        if (j+2 < b){
          if (c[j+2][i] != c[j][i]){
             alpha[int(c[j+2][i]-65)][int(c[j][i]-65)] ++;
             cout << int(c[j+2][i]-65) << " " << int(c[j][i]-65) << " fff " << j+2 << " " << i+2 << " " << j << " " << i << endl;
          }
        }
      }
    }
  }

  for (int i=0;i<a-2;i++){
    for (int j=0;j<b-2;j++){

      if (c[i][j] == c[i+1][j+1]){
        if (j-1 >= 0 && i-1 >= 0){
          if (c[i-1][j-1] != c[i][j]){
             alpha[int(c[i-1][j-1]-65)][int(c[i][j]-65)] ++;
             cout << int(c[i-1][j-1]-65) << " " << int(c[i][j]-65) << " eee " << i-1 << " " << j-1 << " " << i << " " << j <<endl;
          }
        }
        if (j+2 < b && i+2 < a){
          if (c[i+2][j+2] != c[i][j]){
             cout << c[i][j] << " " << c[i+1][j+1] << " " << c[i+2][j+2] <<  " " << i << " " << j <<endl ;
             alpha[int(c[i+2][j+2]-65)][int(c[i][j]-65)] ++;
             cout << int(c[i+2][j+2]-65) << " " << int(c[i][j]-65) << " fff " << i+2 << " " << j+2 << " " << i << " " << j <<endl;
          }
        }
      }
    }
  }
  for (int i=2;i<a;i++){
    for (int j=0;j<b;j++){

      if (c[i][j] == c[i-1][j-1]){
        if (j+1 < b && i+1 < b){
          if (c[i+1][j+1] != c[i][j]){
             alpha[int(c[i+1][j+1]-65)][int(c[i][j]-65)] ++;
             cout << int(c[i+1][j+1]-65) << " " << int(c[i][j]-65) << " eee " << i+1 << " " << j+1 << " " << i << " " << j << endl ;
          }
        }
        if (j-2 >=0 && i-2 >= 0){
          if (c[i-2][j-2] != c[i][j]){
             alpha[int(c[i-2][j-2]-65)][int(c[i][j]-65)] ++;
             cout << int(c[i-2][j-2]-65) << " " << int(c[i][j]-65) << " fff " << i-2 << " " << j-2 << " " << i << " " << j <<endl;
          }
        }
      }
    }
  }
  for(int i=0;i<26;i++){
    for (int j=0;j<26;j++){
      if (alpha[i][j]> maxi){
        cout << i << " " << j << endl;
      }
      maxi = max(maxi,alpha[i][j]);



    }
  }
  cout << maxi;
}
