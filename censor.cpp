#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool visited[]
int main(){
  string a,b;
  cin >> a >> b;
  int place = 0;
  while (place < a.size()-5){
    bool check = true;
    for (int i=place;i<place+b.size();i++){
      if (a[i] != b[i-place]){
        check = false;
      }
    }
    if(check){
      a.erase(a.begin()+place,a.begin()+place+b.size());

      place -= b.size();
      if (place < 0){
        place = -1;
      }
    }
    place++;
  }
  cout << endl;
  for (int i=0;i<a.size();i++){
    cout << a[i];
  }
}
