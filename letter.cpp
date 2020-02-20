#include <iostream>
#include <algorithm>

using namespace std;

bool less(int i, int j){
  int l=0, h = N-max(i,j);
  while(l!=h){
    int mid = (l+h+1)/2;
    if (hash(i,i+mid-1)==hash(j,j+mid-1)){
      l = mid;
    }else{
      h = mid-1;
    }
  }
  if (l == N-i || l== N-j) return true;
  return a[i+len]<a[j+len];
}
