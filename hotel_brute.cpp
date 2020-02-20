#include <iostream>

#include <algorithm>

using namespace std;
bool tree[50001];
int bin_search(int left, int right,int consec){
  if (left+consec<=right) return 1e9;
  int rr = 1e9;
  int mid = (left+right)/2;
  bool l = true;
  for (int j=mid;j<mid+consec;j++){
    if (tree[j]==true) l = false;
  }
  if (l) rr = min(mid,bin_search(left,mid,consec));
  else{
    rr = min(rr,bin_search(left,mid,consec));
    if (rr==1e9) rr = min(rr,bin_search(mid,right,consec));
  }
  return rr;
}
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++){
    int c,d; cin >> c;
    if (c==1){
      cin >> d;
      cout << bin_search(0,b-1,d) << endl;
    }
  }
}
