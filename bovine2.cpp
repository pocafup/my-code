#include <iostream>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

int po1[51][501];
int po2[51][501];
int main(){
  int a,b; cin >> a >> b;
  char d;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> d;
      if (d=='A')po1[i][j] = 0;
      if (d=='T')po1[i][j] = -1;
      if (d=='C')po1[i][j] = -2;
      if (d=='G')po1[i][j] = -3;
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> d;
      if (d=='A')po2[i][j] = 0;
      if (d=='T')po2[i][j] = -1;
      if (d=='C')po2[i][j] = -2;
      if (d=='G')po2[i][j] = -3;
    }
  }


  // for (int i=0;i<b;i++){
  //   for (int j=0;j<b;j++){
  //     for (int k=0;k<b;k++){
  //       for (int l=0;l<a;l++){
  //         aa[i][j][k].insert(po2[l][i]*1024+po2[l][j]*64+po2[l][k]);
  //       }
  //     }
  //   }
  // }
  int ans = 0;
  for (int i=0;i<b;i++){
    for (int j=i+1;j<b;j++){
      for (int k=j+1;k<b;k++){
        set<int> aa;
        for (int l=0;l<a;l++){
          aa.insert(po2[l][i]*1024+po2[l][j]*64+po2[l][k]);
        }
        bool n = true;
        for (int l=0;l<a;l++){
          auto it = aa.lower_bound(po1[l][i]*1024+po1[l][j]*64+po1[l][k]);
          if (*it == po1[l][i]*1024+po1[l][j]*64+po1[l][k]){
            n = false;
            //cout << *it << " " << po1[l][i] << " " << po1[l][j] << " " <<po1[l][k] << endl;
          }
        }
        if (n) {
          //cout << i << " " << j << " " << k << endl;
          ans++;
        }

      }
    }
  }
  cout << ans;
}
