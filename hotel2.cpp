#include <iostream>
#include <algorithm>

using namespace std;
struct seg_tree{
  int lmax,rmax,consec,lazy;
} seg[100001*4];

// void push(long long way,long long left, long long right){
//     if (lazy[way]!=0){
//       N[way] += (right-left+1)*lazy[way];
//       if (left != right) {
//         lazy[way*2]=lazy[way];
//         lazy[way*2+1]=lazy[way];
//       }
//       lazy[way] = 0;
//     }
// }
// int ask(int way,int left, int right){
//
// }
// void clear(int way, int left, int right, int low, int high){
//   if (high<low || left>high) return;
//   if (left==right) {tree[way] = 1;return;}
//   clear(way*2,left,(left+right)/2,low,high);
//   clear(way*2,(left+right)/2+1,left,low,high);
//   tree[way] = tree[way*2]+tree[way*2+1];
// }
void push(int way,int left, int right){
  if (seg[way].lazy==1){
    seg[way] = (seg_tree){0,0,0,0};
    seg[way*2].lazy = 1;
    seg[way*2+1].lazy = 1;
  }
  if (seg[way].lazy==2){
    int re = right-left+1;
    seg[way] = (seg_tree){re,re,re,0};
    seg[way*2].lazy = 2;
    seg[way*2+1].lazy = 2;
  }
}
int ask(int way,int left, int right, int num){
  push(way,left,right);
  if (left==right) return left;
  int mid = (left+right)/2;
  if (seg[way*2].consec>=num) return ask(way*2,left,mid,num);
  if (seg[way*2].rmax+seg[way*2+1].lmax>=num) return mid-seg[way*2].lmax+1;
  return ask(way*2+1,mid+1,right,num);

}
void mark(int way, int left, int right, int low, int high){
  //cout << left << " " << right << endl;
  if (left>high || right< low) return;
  if (left==right && left == low) {seg[way] = (seg_tree) {0,0,0,0};return;}
  if (left>=low && right<=high){
    seg[way] = (seg_tree){0,0,0,0};
    seg[way*2].lazy = 1;
    seg[way*2+1].lazy = 1;
    return;
  }
  int mid = (left+right)/2;
  mark(way*2,left,mid,low,high);
  mark(way*2+1,mid+1,right,low,high);
  seg[way]
}

void make_segmentree(int way, int left, int right){
  int re = right-left+1;
  if (left==right){seg[way] = (seg_tree){re,re,1,0}; return;}
  make_segmentree(2*way,left,(left+right)/2);
  make_segmentree(2*way+1,(left+right)/2+1,right);
  seg[way] = (seg_tree){re,re,seg[2*way].consec+seg[2*way+1].consec,0};
}
int main(){
  int a,b; cin >> a >> b;
  make_segmentree(1,1,a);
  // for (int i=0;i<=a*4;i++) cout << seg[i].consec << " ";
  for (int i=0;i<b;i++){
    int c; cin >> c;
    if (c == 1){
      int d; cin >> d;
      int res = ask(1,1,a,d);
      cout << res << endl;
      mark(1,1,a,res,res+d);
    }
  }
}
