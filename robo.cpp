#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int a,n;
  string b;
  string bb = "ADD";
  vector<int> c;
  cin >> a;
  n = 1;
  cin.ignore();

  for (int i=0;i<a;i++){
    getline(cin,b);
    if (b==bb){
      c.push_back(n);
      n++;
    }else{
      c.erase(c.end()-1);
    }


    }
    cout << c.size() << endl;
    for(int i=0;i<c.size();i++){
      cout << c[i] << endl;
  }
}
