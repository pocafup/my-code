#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int on, int tw){
  return on>tw;
}
int main(){
  int a,b; cin >> a >> b;
  int c[a]; for (int i=0;i<a;i++){cin >> c[i];}
  sort(c,c+a);
  for (int i=0;i<a;i++){cout << c[i] << " ";}
  cout << endl;
  int end = a-1, fir=0;
  int count = 0;
  bool en = true;
  while(end!=fir && en){
    if (c[end]+c[fir] <= b){

      count += fir+1;
      fir++;
    }else if (fir != end){
      end--;
      fir = 0;
    }else{
      // for (int i=0;i<end-fir+1;i++){
      //   count += i;
      // }
      break;
    }
  }
  cout << count;
}
