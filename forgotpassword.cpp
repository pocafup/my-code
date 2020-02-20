#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string sub[1000];
bool bol[1000];
int main(){
  int a,b; cin >> a >> b;
  string str; getline(cin,str);
  for (int i=0;i<b;i++) getline(cin,sub[i]);
  for (int i=0;i<a;i++){
    for (int j=0;j<sub[i].size();j++){
      if (str[b-sub[i].size()] != '?'){
        if (str[b+j-sub[i].size()] != sub[i][j]) bol[i] = true;
      }
    }
  }
  for (int i=0;i<b;i++) cout << bol[i] << " ";
}
