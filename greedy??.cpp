#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  int pos[a+1];
  for (int i=0;i<a;i++){
    cin >> pos[i];
  }
  int po = 0;
  sort(pos,pos+a);
  for (int i=0;i<a;){
    if (pos[i]<b) i++;
    else {po = i; break;}
  }
  for (int j=a;j>=po+1;j--){
    pos[j] = pos[j-1];
  }
  pos[po] = b;
  for (int i=0;i<a+1;i++) cout << pos[i] << " ";
}
