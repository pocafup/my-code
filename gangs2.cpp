#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
int pos[101];
int curr = 1;
int gang,cow;
void fight(int& Gang, int& Cow, int num){
  if (Cow == 0) Gang = num;
  if (Gang ==num) Cow++;
  else Cow--;
}
int check(int Gang, int Cow){
  int temp[101];
  for (int i=1;i<=m;i++) temp[i] = pos[i];
  sort(temp+2,temp+m+1);
  while(temp[m]){
    for (int i=m;i>=2;i--){
      // cout << Cow << endl;
      fight(Gang,Cow,i);
      temp[i]--;
      if (temp[i]>=temp[i-1]) break;
    }
  }
  while(temp[1]!=0){fight(Gang,Cow,1);temp[1]--;}
  return (Gang==1) ? Cow : 0;
}
int main(){
  cin >> n >> m;
  for (int i=1;i<=m;i++) cin >> pos[i];
  int res = check(0,0);
  if (!res) {cout << "NO"; return 0;}
  cout << "YES" << endl << res << endl;
  gang = 0, cow = 0;
  for (int j=1;j<=n;j++){
    for (int i=1;i<=m;i++){
      // cout << pos[i] << endl;
      if (!pos[i]) continue;
      int te_gang = gang,te_cow = cow;
      pos[i]--;
      fight(te_gang,te_cow,i);
      if (check(te_gang,te_cow) == res){
        cout << i << endl;
        gang = te_gang; cow = te_cow;
        break;
      }
      pos[i]++;
    }

  }
}
