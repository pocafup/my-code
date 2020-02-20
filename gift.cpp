#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  int a;
  cin >> a;
  string b[a];
  cin.ignore();
  int re[a];
  memset (re,0,sizeof(re));
  for (int i=0;i<a;i++){
    getline(cin,b[i]);

  }
  string c;
  while (getline(cin,c)){
    int res = 0;
    pair<int,int> d;
    cin >> d.first >> d.second;
    string e;
    for (int i=0;i<c.length();i++){
      cout << c[i];
    }
    cout << endl;
    for (int i=0;i<a;i++){
      if (c.length() == b[i].length()){
        bool test = true;
        for (int j=0;j<b[i].length();j++){
          if (b[i][j] != c[j]){
            test = false;
          }
        }
        if (test){
          re[i] -= d.first;
          res = i;
          break;
        }
      }
    }

    cin.ignore();
    for (int i=0;i<d.second;i++){
      getline(cin,e);
      for (int i=0;i<a;i++){
        if (e.length() == b[i].length()){
          bool test = true;
          for (int j=0;j<b[i].length();j++){
            if (b[i][j] != e[j]){
              test = false;
            }
          }
          if (test){
            re[i] += d.first/d.second;
l
            break;
          }
        }
      }
    }
    re[res] += d.first-(d.first/d.second)*d.second;
    cout << re[0] << endl;
    cout << re[1] << endl;
    cout << re[2] << endl;
    cout << re[3] << endl;
    cout << re[4] << endl;
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b[i].length();j++){
      cout << b[i][j];
    }
    cout << " " << re[i];
  }

}
