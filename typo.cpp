#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  string aa;
  getline(cin,aa);
  int a[100000];
  int b[100000];
  int c[100000];
  int d[100000];


  for (int i=0;i<aa.length();i++){
    if (aa[i] == '('){
      a[i] = 1;
      b[i+1] = b[i]+1;
    }else if(aa[i] == ')'){
      a[i] = -1;
      b[i+1] = b[i]-1;
    }
  }
  bool s = true;
  int p = 0;
  int ans = 0;
  for (int i=0;i<=aa.length();i++){
    c[i] = a[i];
    d[i] = b[i];
  }

  if (b[aa.length()] == 0){
    cout << 0;
  }else if(b[aa.length()] == 2){
    fill(b,b+100000,0);
    for (int i=0;i<aa.length();i++){
      if (c[i] = 1){
        a[aa.length()-i-1] = -1;
      }else{
        a[aa.length()-i-1] = 1;
      }
    }
    for (int i=0;i<aa.length();i++){
      b[i+1] = b[i]+a[i];
    }
  }
  if (b[aa.length()] != 0){
    while (s){
      if (a[p] == -1 && b[p+1]>=0){
        ans++;
        p++;

      }else if(a[p] == 1){
        p++;
      }else{
        ans++;
        s = false;
      }
    }
    cout << ans;
  }
  // for (int i=1;i<aa.length()+1;i++){
  //   cout << b[i] << " ";
  // }
}
