#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
int main(){
  getline(cin,str);
  int pos = 1, sum = 0;
  for (int i=0;i<str.size()-1;i++) {
      if ((int)str[i]-48>=0 && (int)str[i]-48<=9 && pos<=9){sum += pos*((int)str[i]-48);pos++;}
      // else if (str[i] == 'X'){sum+=10*pos;pos++;}
  }
  if (sum%11==10 && str[str.size()-2]=='X') {cout << "Right";return 0;}
  if ((int)str[str.size()-1]-48!=sum%11 && (sum%11!=10 || str[str.size()-1]!='X')){
    str[str.size()-1] = sum%11+48;
    if (sum%11==10 && str[str.size()-1]!='X') str[str.size()-1] = 'X';
    for (int i=0;i<str.size();i++) cout << str[i];
  }else cout << "Right";
}
