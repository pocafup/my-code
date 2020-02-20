#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
  vector<string> vec;
  string b;
  while(cin >> b){
    if (b[0]=='.'){
      break;

    }else{
      vec.push_back(b);
    }
  }
  string c;
  cin >> c;

  int count = 0;
  // for (int i=0;i<vec.size();i++){
  //   cout << vec[i] << " ";
  // }
  bool n = true;
  int pos = 0;
  while(n){

    n = false;
    for (int i=0;i<vec.size();i++){
      bool k = true;
      for (int j=0;j<vec[i].length();j++){
        if (c[pos+j]!=vec[i][j]){
          k = false;
        }
      }
      if (k){
        pos+= vec[i].length();
        n = true;
      }

    }
  }
  cout << pos;
}
