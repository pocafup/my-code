#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  int c[a];
  for (int i=0;i<a;i++){
    cin >> c[i];
  }
  int n = 0;
  sort(c,c+a);
  int count = 0;
  for (int i=a-1;i>=0;i--){
    while(c[i]+c[n]<b && n<i){
      n++;
    }


    if (n==i){
        count+=n;
        n--;
      break;
    }
    count += n;
  }
  while(n>0){
    count+= n+1;
    n--;
  }
  cout << count;
}
