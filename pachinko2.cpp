#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int a;
  cin >> a;
  vector<int> b[a];
  int z = 1;
  for (int i=0;i<a;i++){
    for (int j=0;j<z;j++){
      int m;
      cin >> m;
      b[i].push_back(m);
    }
    z++;
  }
  // z = 1;
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<z;j++){
  //     cout << b[i][j] << " ";
  //   }
  //   cout << endl;
  //   z++;
  // }
  for (int i=a-2;i>=0;i--){
    for (int j=0;j<b[i].size();j++){
      b[i][j] += max(b[i+1][j],b[i+1][j+1]);
    }
  }
  cout << b[0][0];
}
