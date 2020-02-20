#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
  int a; cin >> a;
  string b[a];
  for (int i=0;i<a;i++){
    int c,d; cin >> c >> d;
    string e; cin >> e;
    for(int j=0;j<d;j++){
      string f = e;
      for (int k=e.size()-1;k>=c;k--){
        f.insert(f.begin(),e[k]);
      }
      e = f;
      // cout << "ll";
      // for (int k=0;k<e.size();k++){
      //   cout << e[k];
      // }
      // cout << endl;

    }
  //  cout << "bb";
    for (int j=0;j<e.size();j++){
      cout << e[j];
    }
    cout << endl;
  }

}
