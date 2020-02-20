#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  int a,b,re;
  int pos = 0;
  int laji[100000][3];
  re = 0;
  bool check;
  cin >> a >> b;
  int spot[a][b];
  int non[a][b];
  memset(spot,0,sizeof(spot));
  memset(non,0,sizeof(non));

  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      char e;
      cin >> e;
      spot[i][j] += int(e)-65;

    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      char f;
      cin >> f;
      non[i][j] += int(f)-65;
    }
  }
  for (int i=0;i<b;i++){
    for (int j=i+1;j<b;j++){
      for (int k=j+1;k<b;k++){
        check = true;
        for (int z=0;z<a;z++){
          for (int l=0;l<a;l++){
            cout << char(non[z][i]+65) << char(non[z][j]+65) << char(non[z][k]+65)<< " " << char(spot[l][i]+65) << char(spot[l][j]+65) << char(spot[l][k]+65) << endl;

            if (spot[z][i]==non[l][i] and spot[z][j]==non[l][j] and spot[z][k] == non[l][k]){
              cout << "aa" <<endl;
              check = false;
              break;
            }
          }
        }
        if (check){
          re++;
          cout << "  ccc" << endl;
        }


      }
    }
  }
  for (int i=0;i<b;i++){
    for (int j=i+1;j<b;j++){
      for (int k=j+1;k<b;k++){
        //cout << non[z][i] << " " << non[z][j] << " " << non[z][k] << endl;
        check = true;
        for (int z=0;z<a;z++){
          for (int l=0;l<a;l++){
            cout << char(non[z][i]+65) << char(non[z][j]+65) << char(non[z][k]+65)<< " " << char(spot[l][i]+65) << char(spot[l][j]+65) << char(spot[l][k]+65) << endl;
            if (non[z][i]==spot[l][i] and non[z][j]==spot[l][j] and non[z][k] == spot[l][k]){
              cout << "aa" << endl;
              check = false;
              break;
            }
          }
        }
      }
      if (check){
        re++;
      }
      cout << endl;
    }
  }

  cout << re;
}
