#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int c[b];
  int d[b];
  for (int i=0;i<b;i++){
    int z,x;
    cin >> z >> x;
    if (z<x){
      c[i] = z;
      d[i] = x;
    }else{
      c[i] = x;
      d[i] = z;
    }
  }
  sort(c,c+b);
  sort(d,d+b);
  cout << "aaaaadhfajifjewifjiwaefjaiejfiajfei" << endl;
  for (int i=0;i<b;i++){
    cout << c[i] << " " << d[i] << endl;
  }
  int photo = 1;
  int posc = 0;
  int posd = 0;
  int num = 0;
  while (posc < b && posd < b){
    num = d[posd];
    while (posc<b && c[posc]<num){
      posc++;
    }
    while(posd<b && c[posc]>d[posd]){
      posd++;
    }
    photo++;
  }
  cout << photo;
}
