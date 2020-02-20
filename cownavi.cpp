#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int grid[21][21];
int main(){
  int a; cin >> a;
  for (int i=a-1;i>=0;i--){
    for (int j=a-1;j>=0;j--){
      char b; cin >> b;
      if (b == 'E') grid[i][j] = 0; else grid[i][j] = 1;
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  queue<pair<int,int> > q1, q2;
}
