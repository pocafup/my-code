#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,pos[100001];
void merge(int fir,int sec){
  if (fir==sec) return;
  int mid = (fir+sec)/2;
  merge(fir,mid);
  merge(mid+1,sec);
  queue<int> q;
  int pf = fir, bp = mid+1;
  while(pf<=mid || bp<=sec){
    if (pf<=mid && bp<=sec){
      if (pos[pf]<pos[bp]){q.push(pos[pf]);pf++;}
      else {q.push(pos[bp]);bp++;}
    }else if (pf<=mid){q.push(pos[pf]);pf++;
    }else{q.push(pos[bp]);bp++;}
  }
  for (int i=fir;i<=sec;i++){pos[i] = q.front();q.pop();}
}
int main(){
  cin >> n;
  for (int i=1;i<=n;i++) cin >> pos[i];
  merge(1,n);
  for (int i=1;i<=n;i++) cout << pos[i] << " ";
}
