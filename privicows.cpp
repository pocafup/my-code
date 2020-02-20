#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a; cin >> a;
  int b[a];
  for (int i=0;i<a;i++) cin >> b[i];
  int pos = 0;
  int fin = a-1;

  int count = 0;
  cout << "aa " <<b[fin] << " bb"<< endl;
  while(pos<fin){

    while(b[fin] == 3 or b[fin] == 2){
      fin--;
    }
    for (int i=0;i<a;i++){
      cout << b[i] << " ";
    }
    cout << endl;
    if(fin<=pos){
      break;
    }
    if (b[pos] == 3 && b[fin] == 1){
      b[pos] = b[fin];
      b[fin] = 3;
      count ++;
    }
    pos++;
  }
  cout << count << endl;
  cout << endl;
  fin = a-1;
  pos = 0;
  for (int i=0;i<a;i++){
    cout << b[i] << " ";
  }
  cout << endl;
  while(pos<fin){
    while(b[fin] == 3){
      fin--;
    }
    if (pos>fin){
      break;
    }
    if (b[pos] == 3 && b[fin] == 2){
      b[pos] = b[fin];
      b[fin] = 3;
      count ++;
    }
    pos++;
  }
  for (int i=0;i<a;i++){
    cout << b[i] << " ";
  }
  cout << endl;
  fin = a-1;
  pos = 0;
  while(pos<fin){
    while(b[fin] == 3 or b[fin] == 2){
      fin--;
    }
    if (b[pos] == 2){
      b[pos] = 1;
      b[fin] = 2;
      count ++;
    }
    pos++;
  }
  for (int i=0;i<a;i++){
    cout << b[i] << " ";
  }
  cout << count;
}
