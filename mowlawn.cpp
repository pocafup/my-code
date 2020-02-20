#include <iostream>
#include <algorithm>

using namespace std;

int pos[100001];

void recur(int way,int left,int right){
  if (left!=right){
    recur(way*2,left,(left+right)/2);
    recur(way*2+1,(left+right)/2+1,right);
    tree[way] = min(tree[way*2],tree[way*2+1]);
  }
  if (left == right) tree[way] = N[left];
}
int dp[100001][2];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> pos[i];


}
