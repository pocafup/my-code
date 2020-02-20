#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a; cin >> a;
  for (int i=1;i<=a;i++){
    int b,c; cin >> b >> c;
    int ans = 0;
    for (int j=0;j<b;j++){
      for (int k=0;k<c;k++){
        char d; cin >> d;
        if (d=='~' || d == '<' || d=='>') ans++;
      }
    }
    cout <<"Net #" << i << ": " << ans<< " Fish Nuggets" << endl;
  }
}
