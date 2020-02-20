#include <iostream>
#include <algorithm>

using namespace std;

int pos[1000000];
int maxi;


int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) {
    int c; cin >> c;
    if (i-pos[c]<b && pos[c]!=0){
      maxi = max(maxi,c);
    }
    pos[c] = i;

  }
  cout << maxi;
}
