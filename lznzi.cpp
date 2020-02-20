#include <iostream>
#include <algorithm>

using namespace std;

int n,k,pos[100005],ans = 0;
bool sorted(int a, int b){
  return a>b;
}
int main(){
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> pos[i];
  sort(pos,pos+n,sorted);
  for (int i=0;i<n-k/2;i++){
    ans += pos[i];
  }
  cout << ans;
}
