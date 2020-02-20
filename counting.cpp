#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream cin ("desktop/test.in");
  string s; cin >> s;
  cout << s.length();
}
