#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a; cin >> a;
  for (int i=1;i<=a;i++){
    int temp; cin >> temp;
    int ans = 0;
    for (int j=2;j<=temp;){
      if (temp%j==0){
        temp/=j;
        ans++;
      }else j++;
    }
    if (ans<=3){
      cout << "Pop #" << i << ": " << ans <<  " licks? Your goose is cooked!" << endl;
    }else{
      cout << "Pop #" << i << ": " << "A-one... A-two-HOO... A-" << ans << endl;
    }
  }
}
