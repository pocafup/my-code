#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int order[100005],n,pos[100005],tmp[100005];
int main(){
  cin >> n;
  for (int i=1;i<=n;i++){
    cin >> pos[i];
    tmp[i] = pos[i];
    order[pos[i]] = i;
  }
  sort(tmp+1,tmp+1+n);
  int pt = 1,ans = 0;
  while(pt<=n){
    int point = order[tmp[pt]];
    cout << point << endl;
    if (point==pt) {pt++;continue;}
    ans += tmp[pt]+tmp[point];
    swap(order[tmp[point]],order[tmp[pt]]);

    // order[tmp[point]]
  }
  cout << ans;
}
