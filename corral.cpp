#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#include <vector>
#include <fstream>
using namespace std;

const int INF = 2*1e3;
const int MAXN = 1e8;
pair<int,int> pos[100001];
bool sorted(pair<int,int> aa, pair<int,int> bb){
  return (aa.first==bb.first) ? aa.second<bb.second : (aa.first<bb.first);
}
vector<pair<int,int> > se;
multiset<pair<int,int>,less<pair<int,int> > >::iterator it;
bool start;
int main(){

  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++) {cin >> pos[i].first >> pos[i].second;pos[i].second=(pos[i].second+pos[i].first)%a;}
  sort(pos,pos+b,sorted);
  // cout << endl;
  // for (int i=0;i<b;i++) cout << pos[i].first << " " <<pos[i].second << endl;
  // cout << endl;
  for (int i=0;i<b;i++){
    int it = se.size()-1;

    if (se.empty()){
      se.push_back(make_pair(pos[i].first,pos[i].second));
    }else{
      if (se.size()==1){

        if (se[it].first==pos[i].first && se[it].second<pos[i].second){
          se.erase(se.begin());
          se.push_back(make_pair(pos[i].first,pos[i].second));
        }else{
          se.push_back(make_pair(pos[i].first,pos[i].second));
        }
      }else{

        int so = se.size()-2;
        int ee = se.size()-1;

        bool n = false;
        while (se[so].second>=pos[i].first && pos[i].second>= se[ee].second){
          n = true;
          se.pop_back();
          so--;
          ee--;
        }
        so = se.size()-2;
        ee = se.size()-1;
        bool e = false;
        if (pos[i].second<pos[i].first && !start){
          start = true;
          int kk = pos[i].second+a;
          // cout << kk << endl;
          // cout << pos[i].first << " " << kk << " " << se[so].second << " " << se[ee].second << endl;
          e = true;
          while (se[so].second>=pos[i].first && kk>= se[ee].second){
            n = true;
            se.pop_back();
            so--;
            ee--;
          }
          while(se[ee].second>=pos[i].first && pos[i].second>=se[1].first){
            se.erase(se.begin());
            if(se.size()<2) break;
          }
        }
        if (pos[i].second>se[ee].second || e)se.push_back(make_pair(pos[i].first,pos[i].second));
      }
    }
  }
  int curr = se[0].second-se[0].first;
  bool check = 0;
  for (int i=1;i<se.size();i++){
    // cout << curr << endl;
    int cc = se[i].second<se[i].first? se[i].second+a:se[i].second;
    // cout << cc << " " << se[i].first << " " << se[i-1].second << endl;
    // if (cc>a) cout << cc << endl;
    curr += cc-max(se[i].first,se[i-1].second);
    if (cc>a) curr-= se[i].second-se[0].first+1;
  }
  int e = (se[se.size()-1].second<se[se.size()-1].first)? se[se.size()-1].second: 0;
//   curr+=se[0].first;
    // cout << curr << endl;
//   cout << se[0].second << endl;
  // if(se[0].second>INF) curr+=MAXN;
  // cout << curr << endl;
  if(curr<a-1) check = true;
  cout << se.size()+check;
}
