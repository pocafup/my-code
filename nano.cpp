#include <iostream>
#include <algorithm>
#include <math.h>
#include <ctype.h>

using namespace std;
int n;
int main(){
  cin >> n;
  for (int i=1;i<=n;i++){
    //cin.ignore();
    string a; cin >> a;
    int ans = 1;
    for (int j=0;j<a.length();j++){
      if (not ((char)a[j]!=(char)92 && (char)a[j]!='/' && (char)a[j]!='|' && (char)a[j]!='-')) ans++;
    }
    cout << "Cyborg #" << i << ": ";
    if (ans==1) cout << ans << " piece? You're supposed to be stronger than this!" << endl;
    else cout << ans << " pieces!" << endl;
  }
  // for (int i = 0; i < n; i++){
  //   double x, y; cin >> x >> y;
  //   if (pow(x, 2)/4 >= y){
  //     cout << "Wall #" << i + 1 << ": " << "YES" << endl;
  //   }else {
  //       cout << "Wall #" << i + 1 << ": " << "NO" << endl;
  //   }
  // }
}
