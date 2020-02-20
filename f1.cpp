#include <iostream>
#include <string>

using namespace std;

int main(){
  int a; cin >> a;
  string str[a];
  for (int i=0;i<a;i++){
    cin >> str[i];
    if ((int(str[i][str[i].size()-1])-48)%2!=0){
      cout << "odd" << endl;
    }else{
      cout << "even" << endl;
    }

  }
}
