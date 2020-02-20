#include <iostream>
#include <algorithm>

using namespace std;
int d;
int f(int spos, int ipos, int s,int l){
  f(s,l) = min(f(spos-d,s-1,l)+abs(spos-ipos),f(s,l-1)+abs(spos-ipos));
  return f(s,l);
}

int nums[10000];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> nums[i];
}
