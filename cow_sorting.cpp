#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, pos[100001],tmp[100001],order[100001],ans = 0,ct = 0;
int find(int num){
  for (int i=0;i<n;i++){
    if (pos[i]==num) return i;
  }
  return -1;
}
bool vis[100001];
int main(){
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> pos[i];
    tmp[i] = pos[i];
  }
  for (int i=1;i<=n;i++) order[tmp[i]] = i;

  sort(tmp+1,tmp+1+n);
  int pt = 1;
  while(ct<n){
    int point = order[tmp[pt]];
    cout << "point = " << point << endl;
    // cout << tmp[pt] << " " << order[tmp[pt]] << " " << tmp[point] << endl;
    // cout << pos[point] << " " << tmp[point] << endl;
    cout << point << " "<< order[point] << endl;
    int nxt = order[point];
    if (pos[point]==tmp[point]){pt++;ct++;continue;}
    //int mok = find(tmp[pt]);
    ans += pos[point]+pos[nxt];
    swap(order[point],order[pos[point]]);
    swap(pos[point],pos[order[point]]);
    ct++;
    for (int i=1;i<=n;i++) cout << pos[i] << " ";
    cout << endl;
  }

  cout << ans;
}
/*
4
8
1
2
4
*/
