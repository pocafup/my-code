#include <iostream>
#include <deque>

using namespace std;

deque<int> de;
int main(){
  int a;
  cin >> a;
  int zz = 1;
  for (int i=0;i<a;i++){
    char b;
    cin >> b;
    if (b == 'A'){
      char c;
      cin >> c;
      if (c == 'L'){
        de.push_front(zz);
        zz++;
      }else{
        de.push_back(zz);
        zz++;
      }
    }else{
      int e;
      char d;
      cin >> d >> e;
      if (d == 'L'){
        for (int j=0;j<e;j++){
          de.pop_front();
        }
      }else{
        for (int j=0;j<e;j++){
          de.pop_back();
        }
      }
    }
  }
  while (de.size()){
    cout << de.front() << endl;
    de.pop_front();
  }
}
