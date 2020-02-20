#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int times(int aa){
  int bb = 1;
  for(int i=0;i<aa;i++){
    bb = bb*10;
  }
  return bb;
}
int main(){
  string a,b;
  cin >> a >> b;
  int t = 0;
  //cout << a.length() <<" " << b.length();
  for (int i=a.length();i<=b.length();i++){
    int c[i];
    for (int j=0;j<=9;j++){
      for (int k=0;k<i;k++){
        c[k] = j;
      }
      for (int l=0;l<=9;l++){
        for (int m=0;m<i;m++){
          int ne = c[m];
          c[m] = l;
          int n=1;
          int num = c[0];
          while (n!=i && l!=j){
            num = num*10+c[n];
            n++;
          }
          // cout << c[0] << c[1] <<c[2] << endl;
          // cout << num <<" "<<stoi(a) << " " <<stoi(b)<< endl;
          if (num>=stoi(a) && num<=stoi(b) && num>=times(i-1)){
            t++;
            //cout << num << endl;
          }
          c[m] = ne;
        }
      }

    }
  }
  cout << t;
}
