#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b,c;
  int mini = 10000;
  cin >> a >> b >> c;
  int d[c];
  for (int i=0;i<c;i++){
    cin >> d[i];
  }
  sort(d,d+c);
  for (int i=0;i<c;i++){
    for (int j=i;j<c;j++){
      if (d[j]-d[i]-1>b && j-i<mini){
        mini = j-i;
      }
    }
  }
  if (mini == 10000){
    mini = b+1;
  }
  cout << mini-1;
}
