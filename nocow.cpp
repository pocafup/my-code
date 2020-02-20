#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string st[101][31];
int main(){
  int n,k; cin >> n >> k;
  for (int i=0;i<n;i++){
    int tot = -1;
    for (int j=0;j<19;j++) cin.ignore();
    for (int j=0;j<k-4;j++){
      cin >> st[i][++tot];
      // for (int l=0;l<st[i][tot].length();l++){
      //   cout << st[i][tot][l];
      // }
      // cout << endl;
    }
    for (int j=0;j<6;j++) cin.ignore();
  }
  sort(st,st+n);
}
