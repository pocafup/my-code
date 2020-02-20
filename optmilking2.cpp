#include <iostream>
#include <algorithm>

using namespace std;
long long n,d;
long long pos[40005];
long long segtree[300010][2][2];
void make_segtree(long long way, long long l, long long r){
  if (l==r) {segtree[way][1][1] = pos[l]; return;}
  long long mid = (l+r)/2;
  make_segtree(way*2,l,mid);
  make_segtree(way*2+1,mid+1,r);
  segtree[way][0][0] = max(segtree[way*2][0][1]+segtree[way*2+1][0][0],segtree[way*2][0][0]+segtree[way*2+1][1][0]);
  segtree[way][1][0] = max(segtree[way*2][1][1]+segtree[way*2+1][0][0],segtree[way*2][1][0]+segtree[way*2+1][1][0]);
  segtree[way][0][1] = max(segtree[way*2][0][1]+segtree[way*2+1][0][1],segtree[way*2][0][0]+segtree[way*2+1][1][1]);
  segtree[way][1][1] = max(segtree[way*2][1][1]+segtree[way*2+1][0][1],segtree[way*2][1][0]+segtree[way*2+1][1][1]);
}
void update(long long way, long long l, long long r, long long pos ,long long val){
  if (pos<l || pos> r) return;
  if (pos==l && pos==r) {segtree[way][1][1] = val; return;}
  long long mid = (l+r)/2;
  update(way*2,l,mid,pos,val);
  update(way*2+1,mid+1,r,pos,val);
  segtree[way][0][0] = max(segtree[way*2][0][1]+segtree[way*2+1][0][0],segtree[way*2][0][0]+segtree[way*2+1][1][0]);
  segtree[way][1][0] = max(segtree[way*2][1][1]+segtree[way*2+1][0][0],segtree[way*2][1][0]+segtree[way*2+1][1][0]);
  segtree[way][0][1] = max(segtree[way*2][0][1]+segtree[way*2+1][0][1],segtree[way*2][0][0]+segtree[way*2+1][1][1]);
  segtree[way][1][1] = max(segtree[way*2][1][1]+segtree[way*2+1][0][1],segtree[way*2][1][0]+segtree[way*2+1][1][1]);
}
int main(){
  cin >> n >> d;
  for (long long i=1;i<=n;i++) cin >> pos[i];
  make_segtree(1,1,n);
  long long ans = 0;
  for (long long i=0;i<d;i++){
    long long a,b; cin >> a >> b;
    update(1,1,n,a,b);
    ans+=max(max(segtree[1][0][0],segtree[1][0][1]),max(segtree[1][1][0],segtree[1][1][1]));
  }
  cout << ans;
}
