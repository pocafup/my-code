#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  long a,maxi,maxi2,mini2,mini;
  maxi = 0;
  maxi2 = 0;
  mini2 = 0;
  mini = 1000000000;
  cin >> a;
  bool arr[1000000];
  memset(arr,false,sizeof(arr));
  for (int i=0;i<a;i++){
    int d,e;
    cin >> d >> e;
    if (maxi<e){
      maxi = e;
    }
    if (mini>d){
      mini = d;
    }
    for (int j=d;j<e;j++){
      arr[j] = true;
    }
  }
  bool cc = true;
  int x = 0;
  for (int i=mini;i<maxi;i++){
    if (cc==arr[i] && cc == true){
      x++;
      if (i==maxi-1){
        if (maxi2<x){
          maxi2 = x;
        }
      }
    }else if(cc!= arr[i] && cc == true){
      if (maxi2<x){
        maxi2 = x;
      }
      x = 1;
      cc = false;
    }else if(cc == arr[i] && cc == false){
      x++;
      if (i==maxi-1){
        if (mini2<x ){
          mini2 = x;
        }
      }
    }else{
      if (mini2<x){
        mini2 = x;
      }
      x=1;
      cc = true;
    }
  }

  cout << maxi2 << " " << mini2;
}
