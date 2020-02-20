#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int seg[40000005];
int lazy[40000005];
int n,q;
void push(int way){
  if (lazy[way]){
    seg[way] = min(seg[way],lazy[way]);
    lazy[way*2] = min(lazy[way*2],lazy[way]);
    lazy[way*2+1] = min(lazy[way*2+1],lazy[way]);
    lazy[way] = 0;
  }
}
bool ask(int way, int le, int ri, int low, int high, int val){
  // cout << le << " " << ri << endl;
  if (low<=le && high>=ri) return seg[way]>=val;
  if (le==ri) return true;
  push(way);
  if (high<le || low>ri) return true;
  int mid = (le+ri)/2;
  return ask(way*2,le,mid,low,high,val) && ask(way*2+1,mid+1,ri,low,high,val);
}
void change(int way, int le, int ri, int low, int high, int val){
  // cout << le << " " << ri << endl;
  push(way);
  if (low<=le && high>=ri) {
    if (seg[way]>val){
      lazy[way] = val;
      push(way);
    }
  }
  if (le==ri) return;
  if (high<le || low>ri) return;
  int mid = (le+ri)/2;
  change(way*2,le,mid,low,high,val);
  change(way*2+1,mid+1,ri,low,high,val);
  seg[way] = min(seg[way*2],seg[way*2+1]);
}
int main(){
  ifstream cin("desktop//P2898_2.in");
  cin >> n >> q;
  // cout << n << q << endl;
  memset(seg,0x3f3f,sizeof(seg));
  for (int i=1;i<=q;i++){
    int a,b,c; cin >> a >> b >> c;
    if (!ask(1,1,n,a,b,c)) {cout << i; exit(0);}
    change(1,1,n,a,b,c);
  }
  cout << 0;
}
