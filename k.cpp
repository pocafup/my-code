#include <iostream>
using namespace std;

int main(){
  int a,b;
  cin >> a;
  int x[100000];
  for (int i=0;i<a;i++){
    cin >> x[i];
  }
  cin >> b;
  for (int i=a;i<a+b;i++){
    cin >> x[i];
  }
  int pos = 0;
  while(pos<a+b){
    for (int i=pos;i<a+b;i++){
      if (x[pos]>x[i]){
        int temp = x[pos];
        x[pos] = x[i];
        x[i] = temp;
      }
    }
    pos++;
  }
  cout << endl;
  for (int i=0;i<a+b;i++){
    cout << x[i] << " ";
  }
}
