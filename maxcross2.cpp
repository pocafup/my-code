
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
multiset<int> se;
int n,m,k,pos[100005],ans = 1e9;
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}
int main(){
  // setIO("maxcross");
  cin >> n >> m >> k;
  for (int i=0;i<k;i++) cin >> pos[i];
  sort(pos,pos+k);
  int pt = 0;
  for (int i=1;i<=n-m+1;i++){
    // cout << i << " " << se.size() << endl;
    int ri = i+m;
    if (pt<k) while(pos[pt]<ri && pt<k) {se.insert(pos[pt]);pt++; if (pt==k) break;}
    ans = min(ans,(int)se.size());
    if (se.size()) if (se.find(i)!=se.end()) se.erase(se.find(i));
  }
  cout << min(ans,k);
}
