#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
const int has = 1e9+7;
int data[100001];
int pos[20001];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> pos[i];
  data[0] = 11;
  for (int i=1;i<=a;i++) data[i] = (data[i-1]*11)%has;
  int ans = 0;
  for (int i=1;i<=a;i++){
    int curr = 0,po=i;
    priority_queue<int> rep;
    for (int k=i-1;k>=0;k--){
      curr = ((curr+(pos[k]*data[k-i+1])%has)+has)%has;
    }
    cout << curr << endl;
    rep.push(curr);
    while(po<a){
      curr = ((curr*11)%has-(pos[po-i]*data[po-i])%has+pos[po]%has+has)%has;
      rep.push(curr);
      po++;
    }
    int now = rep.top();
    int big = 1;
    rep.pop();
    while(!rep.empty()){
      if (now==rep.top()) big++;
      else{
        big=1;
        now = rep.top();
      }
      rep.pop();
    }
    if (big>=b) ans = i;
  }
  cout << ans;
}
