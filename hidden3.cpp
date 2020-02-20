#include <iostream>
#include <algorithm>

using namespace std;
char pos[100001];
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >> pos[i];
  int fir=0,sec=1,len=0;
  bool n = false;
  while(fir<a && sec<a){
    len = 0;
    while(pos[(fir+len)%a]==pos[(sec+len)%a] && len<a) len++;
    if (pos[(fir+len)%a]==pos[(sec+len)%a]) {cout << a; n = true; break;}
    if (pos[(fir+len)%a]<pos[(sec+len)%a]) sec+=len+1;
    else fir+=len+1;
    if (fir==sec) fir++;
  }
  fir<sec?cout << fir:cout << sec;
}
