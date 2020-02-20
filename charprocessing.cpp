#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a,b;
string c[51],d[51];
bool e[51][4];
int ch[51];
int main(){
  cin >>a>>b;
  int times = 1;
  int num = 0,ans = 0;
  cin.ignore();
  for (int i=0;i<a;i++) {
    getline(cin,c[i]);

  }
  cout << endl;
  for (int i=0;i<a;i++) getline(cin,d[i]);
  char check[4] = {'A','T','C','G'};
  for (int i=0;i<a;i++) {
    for (int j=0;j<c[i].length();j++) cout << c[i][j];
    cout << endl;
  }
  for (int i=0;i<a;i++) {
    for (int j=0;j<d[i].length();j++) cout << d[i][j];
    cout << endl;
  }
  for (int i=0;i<b;i++){
    for (int j=0;j<a;j++){
      for (int k=0;k<4;k++){
        if (d[j][i] == check[k]) e[i][k] = true;
      }
    }
    int temp = 0;
    for (int k=0;k<4;k++){

      if (e[i][k] == false){
        //cout << i << " " << k << " " << check[k] << endl;
        for (int j=0;j<a;j++){
          if (c[j][i] == check[k]){
            temp++;
            break;
          }
        }
      }
    }
    //cout << temp << endl;
    if(temp!=0){
      ch[i] = temp;
      //times*=temp;
    }
  }
  for (int i=0;i<b;i++){
    for (int j=i+1;j<b;j++){
      for (int k=j+1;k<b;k++){
        if (ch[i]!=0 || ch[j]!=0 || ch[k]!=0){
          int ti = 1;
          if (ch[i]!=0) ti*=ch[i];
          if (ch[j]!=0) ti*=ch[j];
          if (ch[k]!=0) ti*=ch[k];
          ans += ti;
          cout << i << " " << j << " " << k << endl;
        }
      }
    }
  }
  cout << ans;
}
