/*
ID:dx424391
PROG: lifeguard
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

bool sorted(pair<int,int> aa, pair<int,int> bb){
  if (aa.first<bb.first)return true;
  if (aa.first==bb.first && aa.first<bb.first) return true;
  return false;

}
pair<int,int> pos[100001];
int overlap[100001];
vector<pair<int,int> > vec;
int main(){
  ofstream cout("lifeguards.out");
  ifstream cin ("lifeguards.in");
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >> pos[i].first >> pos[i].second;
  sort(pos,pos+a);
  for (int i=0;i<a;i++){
    if (i-1>=0){
      if (pos[i].first<pos[i-1].second) overlap[i]+= pos[i-1].second-pos[i].first;
    }
    if (i+1<a){
      if (pos[i].second>pos[i+1].first) overlap[i]+=pos[i].second-pos[i+1].first;
    }
  }
  int maxi = 1e8;
  int place = 0;
  for (int i=0;i<a;i++){
    int cc = pos[i].second-pos[i].first-overlap[i]+1;
    if (maxi>cc){
      maxi = cc;
      place = i;
    }
  }
  int ans = 0;
  for (int i=0;i<a;i++){
    if (i!=place){
      vec.push_back(make_pair(pos[i].first,-1));
      vec.push_back(make_pair(pos[i].second,1));
    }
  }
  sort(vec.begin(),vec.end(),sorted);
  int prefix = 0;
  int start = vec[0].first;

  for (int i=0;i<vec.size();i++){
    prefix+=vec[i].second;
    if (prefix == 0){
      ans += vec[i].first-start;
      if (i<vec.size()-1){
        start = vec[i+1].first;
      }
    }
  }
  //for (int i=0;i<vec.size();i++) cout << vec[i].first << " " << vec[i].second<<endl;
  cout << ans;
}
