#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>


using namespace std;

int main(){
  int a,b; cin >> a >> b;
  string c[a], d[b];
  for (int i=0;i<a;i++) {
    cin >> c[i];
    for (int j=0;j<c[i].length();j++){
      c[i][j] = toupper(c[i][j]);
    }
  }
  for (int i=0;i<b;i++) {
    cin >> d[i];
    for (int j=0;j<d[i].length();j++){
      d[i][j] = toupper(d[i][j]);
    }
  }
  for (int i=0;i<a;i++){
    int count = 0;
    for (int j=0;j<b;j++){
      int pos = 0;
      int found = -1;
      bool n = 0;
      while(pos<d[j].length()){
        found = c[i].find(d[j][pos],found+1);
        //cout << found << " " << d[j][0] << endl;
        if ((found == 0 && d[j][0]!=c[i][0]) or found == -1){
          n = 1;
          break;
        }
        pos++;
      }
      //cout << endl;
      if (!n){
        count++;
      }
    }
    cout << count << endl;
  }
}
