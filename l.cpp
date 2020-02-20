#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  int c[b];
  for (int i=0;i<b;i++) cin >> c[i];
  int maxi = 0;
  for (int i=0;i<=a;i++){
    int mini = 1000;
    for (int j=0;j<b;j++){
      int tru = i;
      int fal = a-i;
      int tru2 = c[j];
      int fal2 = a-c[j];
      if (j==0){
        //cout << tru << " " << fal << " " << tru2 << " " << fal2 << endl;
      }
      if (tru>=fal2){
        mini = min(mini,tru-fal2);
      }else if (fal>= tru2){
        mini = min(mini,fal-tru2);
      }
    }
    maxi = max(mini,maxi);
  }
  cout << maxi;
}
