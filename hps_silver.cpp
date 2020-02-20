#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
int hoof[100001];
int paper[100001];
int scissor[100001];
char fmove[100001];
int main(){
  ifstream cin ("hps.in");
  ofstream cout("hps.out");
  int a; cin >> a;


  for (int i=0;i<a;i++) {
    cin >> fmove[i];
    if (i==0){
      if (fmove[i]=='P')paper[i] = 1;
      if (fmove[i]=='H')hoof[i] = 1;
      else scissor[i] = 1;
    }else{
      paper[i] = (fmove[i]=='P') ? paper[i-1]+1 : paper[i-1];
      hoof[i] = (fmove[i]=='H') ? hoof[i-1]+1 : hoof[i-1];
      scissor[i] = fmove[i]== 'S' ? scissor[i-1]+1:scissor[i-1];
    }
  }
  int ans = 0;
  for (int i=0;i<a;i++){
    ans = max(ans,paper[i]+hoof[a-1]-hoof[i]);
    ans = max(ans,paper[i]+scissor[a-1]-scissor[i]);
    ans = max(ans,hoof[i]+paper[a-1]-paper[i]);
    ans = max(ans,hoof[i]+scissor[a-1]-scissor[i]);
    ans = max(ans,scissor[i]+hoof[a-1]-hoof[i]);
    ans = max(ans,scissor[i]+paper[a-1]-paper[i]);
  }
  cout << ans;
}
