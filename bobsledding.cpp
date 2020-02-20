#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int,int> pp;
pp pos[50001];
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >>pos[i].first >> pos[i].second;
  sort(pp,pp+a);
  set<pair<int,int> > lset,rset;
  int begin = 0;
  set<int> lsetx,lsety, rsetx,rsety;
  for (int i=0;i<a;i++){
    rset.insert(make_pair(pos[i].first,pos[i].second));
  }
  while(begin<a){
    lsetx.insert(pos[begin].first);
    lsety.insert(pos[begin].second);

  }
}
