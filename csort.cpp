#include <iostream>
#include <algorithm>

using namespace std;
int n, pos[100001],tmp[100001], ans = 0;
bool vis[100001];
int find(int num, int st){
  for (int i=st-1;i>=0;i--){
    if (pos[i]==num && pos[i]!=tmp[i]) return i;
  }
  return -1;
}
// bool sorted(int a, int b) {return a>b;}
int main(){
  cin >> n;
  for (int i=0;i<n;i++) {cin >> pos[i];tmp[i] = pos[i];}
  sort(tmp,tmp+n);
  int pt = n-1;
  while(pt>=0){
    // cout << pt << " " << pos[pt] << " " << tmp[pt] << endl;
    if (pos[pt]==tmp[pt]) vis[pt] = true;
    if (vis[pt]) {
      pt--;
    }else{
      int tog = find(tmp[pt],pt);
      // cout << tog << endl;
      ans += pos[pt]+pos[tog];
      swap(pos[pt],pos[tog]);
      vis[pt] = true;
      pt--;
      // for (int i=0;i<n;i++) cout << pos[i] << " ";
      // cout << endl;
    }
  }
  cout << ans;
}
