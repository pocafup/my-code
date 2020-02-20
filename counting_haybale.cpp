#include <iostream>
#include <algorithm>

using namespace std;
long long seg[4*200001];
long long lazy[4*200001];
long long pos[200001],mini[4*200005];
long long n,m;
void push(long long way,long long left, long long right){
    if (lazy[way]!=0){
      seg[way] += (right-left+1)*lazy[way];
      mini[way]+= lazy[way];
      if (left != right) {
        lazy[way*2]+=lazy[way];
        lazy[way*2+1]+=lazy[way];
      }
      lazy[way] = 0;
    }
}
long long min(long long a, long long b){return a<b? a : b;}
void change(long long way,long long val, long long left,long long right,long long low, long long high){
  push(way,left,right);
  if (left>high || right<low) return;
  if (left>=low && right<=high) {
    lazy[way] = val;
    push(way,left,right);
    return;
  }
  change(way*2,val,left,(left+right)/2,low,high);
  change(way*2+1,val,(left+right)/2+1,right,low,high);
  seg[way] = seg[way*2]+seg[way*2+1];
  mini[way] = min(mini[way*2],mini[way*2+1]);
}
long long sum(long long way,long long left,long long right,long long low, long long high) {
  push(way,left,right);
  if (left>high || right<low) return 0;
  if (left>=low && right<=high) {
    return seg[way];
  }
  return sum(2*way,left, (left + right)/2, low, high)+sum(2*way+1,(left + right)/2+1, right, low, high);
}
long long minimum(long long way, long long left, long long right, long long low, long long high){
  push(way,left,right);
  if (left>high || right<low) return 1e9;
  if (left>=low && right<=high) {
    return mini[way];
  }
  return min(minimum(2*way,left, (left + right)/2, low, high),minimum(2*way+1,(left + right)/2+1, right, low, high));
}
void make_tree(long long way,long long left, long long right){
  if (left == right){
    seg[way] = pos[left];
    mini[way] = pos[left];
  }else{
    make_tree(2*way,left,(left+right)/2);
    make_tree(2*way+1,(left+right)/2+1,right);
    seg[way] = seg[2*way]+seg[2*way+1];
    mini[way] = min(mini[way*2],mini[way*2+1]);
  }
}

int main(){
  cin >> n >>  m;
  for (long long i=1;i<=n;i++) cin >> pos[i];
  make_tree(1,1,n);
  // for (long long i=1;i<=4*n;i++) cout << mini[i] << " ";
  for (long long i=0;i<m;i++){
    char ind; cin >> ind;
    if (ind == 'P'){
      long long c,d,e; cin >> c >> d >> e;
      change(1,e,1,n,c,d);
    }else if (ind=='S'){
      long long c,d; cin >> c >> d;
      cout << sum(1,1,n,c,d) << endl;
    }else{
      long long c,d; cin >> c >> d;
      cout << minimum(1,1,n,c,d) <<endl;
    }
  }
}
