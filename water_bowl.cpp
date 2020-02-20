#include <iostream>
#include <algorithm>

using namespace std;

void solve(){
  int a[20];
  int copy[20];
  int mini = 10000;
  bool l = false;
  for (int i=0;i<20;i++){
    cin >> a[i];
    copy[i] = a[i];
  }
  for (int i=0;i<(1<<20);i++){

    int count = 0;
    for (int j=0;j<20;j++){
      int temp = i>>j;
      if (temp&1){
        for(int k=j-1;k<j+2;k++){
          if (i==1){
            cout << k;
          }
          if (k<0 ||k>=20){
            continue;
          }
          if (copy[k]==0){
            copy[k] = 1;
          }else{
            if(i==1){
              cout << copy[k] << " aa" << endl;
            }
            copy[k] = 0;
          }
        }


      count ++;
      }
    }
    if (i==1){
      for (int o=0;o<20;o++){
        cout << copy[o] << endl;
      }
    }
    for (int aa=0;aa<20;aa++){
      if (copy[aa] != 0){
        l = true;
      }
    }
    if (mini>count && l == false){
      mini = count;
    }
    for(int x=0;x<20;x++){
      copy[x] = a[x];
    }
  }
  cout << mini;
}

int main(){
  solve();
}
