#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;
int b,c,d,e;

pair<pair<int,pair<int,int> >,int> pos[2002];
set<pair<int,int> > yset;
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++){
    cin >> b >> c >> d >> e;
    pos[i*2] = make_pair(make_pair(b,make_pair(c,e)),1);
    pos[i*2+1] = make_pair(make_pair(d,make_pair(c,e)),-1);
  }
  sort(pos,pos+a*2);

  int prefix = 0;
  int currpos = 0;
  int ans = 0;
  for(int i=0;i<a*2;i++){
    int pff = pos[i].first.first;
    int pfsf = pos[i].first.second.first;
    int pfss = pos[i].first.second.second;
    int ps = pos[i].second;
    cout << "   " << pff << " " << pfsf << " " << pfss << " " << ps << endl;
    if (ps ==1){
      yset.insert(make_pair(pfsf,1));
      yset.insert(make_pair(pfss,-1));
    }else{
      yset.erase(make_pair(pfsf,1));
      yset.erase(make_pair(pfss,-1));
    }

    int n = 0;
    int bound = 0;
    int k = 0,len = 0;
    if (prefix>=1){
      while(n!=yset.size()){
        n++;
        set<pair<int,int> >::iterator it = yset.upper_bound(make_pair(bound,-1));
        set<pair<int,int> >::iterator it2 = yset.upper_bound(make_pair(bound,1));
        if ((*it).first>(*it2).first && (*i)) it = it2;
        cout << "       " << (*it).first << " " << (*it).second << " " << n<< " " <<bound<< " " << k <<  endl;
        if (k>0){
          len+= (*it).first-bound;
        }
        if ((*it).second == -1)k++;
        else k--;
        bound = (*it).first;
      }
      cout << len << " " << currpos << endl;
      ans += (pff-currpos)*len;
    }

    currpos = pff;
    prefix += ps;

  }
  cout << ans;
}
