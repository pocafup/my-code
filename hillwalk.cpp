y#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define pp pair<pair<int,int>,pair<int,int> >
bool sorted(pp aa, pp bb){
  if (aa.second.first!=bb.second.first) return aa.second.first < bb.second.first;
  if (aa.first.first!=bb.first.first) return aa.first.first<bb.first.first;
  return aa.second.second < bb.second.second;
}
double find_slope(pp point){
  double aa = (double)(point.second.second-point.first.second)/(double)(point.second.first-point.first.first);
  return aa;
}
pp node[100001];
double slope[100001];
int main(){
  ifstream cin ("hillwalk.in");
  ofstream cout("hillwalk.out");
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >> node[i].first.first >> node[i].first.second >> node[i].second.first >> node[i].second.second;
  pp curr = node[0];
  sort(node,node+a,sorted);
  for (int i=0;i<a;i++) slope[i] = find_slope(node[i]);
  int pos = 1, ans = 1;

  for (int i=0;i<a;i++) if (node[i].first.first == 0 && node[i].first.second == 0) pos = i+1;
  // cout << "pos = " << pos << endl;
  for (int i=0;i<a;i++){
    // cout << node[i].first.first << " " <<node[i].first.second << " " <<
    //         node[i].second.first << " " << node[i].second.second << endl;
  }
  //or (int i=0;i<a;i++) cout << slope[i] << endl;
  while(pos!=a){
    priority_queue<pair<double,int> > q;
    while(pos<a){

      if (curr.second.first<node[pos].second.first && curr.second.first>=node[pos].first.first){
        double re = (double)slope[pos]*(curr.second.first-node[pos].first.first)+node[pos].first.second;
        if (re<=curr.second.second) q.push(make_pair(re,pos));
      }

      if (pos+1==a) break;
      pos++;


    }

    // cout << pos << "pp"<< " " << q.size()<<endl;
    if (!q.size())break;
    curr = make_pair(make_pair(node[q.top().second].second.first,q.top().first),node[q.top().second].second);
    pos = q.top().second+1;

    // cout << node[q.top().second].first.first << " " <<node[q.top().second].first.second << " " <<
    //         node[q.top().second].second.first << " " << node[q.top().second].second.second << endl;
    ans ++;
    if (pos >= a) break;
  }
  cout << ans;
}
