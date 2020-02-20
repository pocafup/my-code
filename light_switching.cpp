#include <iostream>
#include <algorithm>

using namespace std;
int N[100001*4];
int lazy[100001*4];
int ans = 0;
pair<int,pair<int,int> > M[100001*4];
void push(int way,int left, int right){
    if (lazy[way]!=0){
      N[way] = right-left+1-N[way];
      if (left != right) {
        lazy[way*2]^=1;
        lazy[way*2+1]^=1;
      }
      lazy[way] = 0;
    }
}
void recur(int way,int left,int right,int low, int high){
  push(way,left,right);
  if (left>high || right<low) return;
  if (left>=low && right<=high) {
    lazy[way] = 1;
    push(way,left,right);
    return;
  }
  recur(way*2,left,(left+right)/2,low,high);
  recur(way*2+1,(left+right)/2+1,right,low,high);
  N[way] = N[way*2]+N[way*2+1];
}
int sum(int way,int left,int right,int low, int high) {
  push(way,left,right);
  if (left>high || right<low) return 0;
  if (left>=low && right<=high) {
    return N[way];
  }
  return sum(2*way,left, (left + right)/2, low, high)+sum(2*way+1,(left + right)/2+1, right, low, high);
}
int main(){
  int a,b; cin >> a>>b;
  cout << endl;
  for (int i=0;i<b;i++) {
    int c,d,e; cin >> c >> d >> e;
    if (c == 0)recur(1,1,a,d,e);
    if (c == 1) cout <<sum(1,1,a,d,e) << endl;
  }
}
