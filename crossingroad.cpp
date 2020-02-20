#include <iostream>
#include <algorithm>

using namespace std;
int n,ft[100001];
int pos[100001];
void update(int x, int v){
  while(x<=n){
    ft[x] += v;
    x += (x&-x);
  }
}
int query(int x){
  return x>0 ? ft[x]+query(x-(x&-x)) : 0;
}

int main(){
  cin >> n;
  for (int i=0;i<n;i++){
    cin >> pos[i];
  }
  int ans = 0;
  for (int i=n-1;i>=0;i--){
    int le = query(pos[i]-1);
    int right = query(n)-query(pos[i]);
    if (max(le,right)>min(le,right)*2) ans++;
    update(pos[i],1);
  }
  cout << ans;
}
