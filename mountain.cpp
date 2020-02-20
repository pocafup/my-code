/*
ID:dx424391
PROG: mountains
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;
bool func(pair<int,int> i,pair<int,int> j){
  if(i.first != j.first){
    return i.first < j.first;
  }else{
    return i.second > j.second;
  }

}

int main(){
  // ofstream cout("mountains.out");
  // ifstream cin("mountains.in");
  int a;
  cin >> a;
  pair<int,int> b[a];
  int c,d;
  for (int i=0;i<a;i++){
    cin >> c >> d;
    b[i].first = c;
    b[i].second = d;
  }
  int count = 1;

  sort(b,b+a,func);

  vector<pair<int,int> > q;
  vector<pair<pair<int,int>,int> > q2;
  pair<int,int> f;
  pair<pair<int,int>,int> f2;
  f.first = b[0].first;
  f.second = b[0].second;
  f2.first = f;
  f2.second = 0;
  q.push_back(f);
  q2.push_back(f2);
  for (int i=1;i<a;i++){
    bool aa = true;
    for (int j=0;j<q.size();j++){
      if (q[j].first+q[j].second-b[i].first >= b[i].second){
        aa = false;
      }

    }
    while(!q.empty()){
      if(q[0].first+q[0].second-b[i].first < 0){
        q.erase(q.begin());
      }else break;

    }

    if (aa){
      count++;
      f.first = b[i].first;
      f.second = b[i].second;
      f2.first = f;
      f2.second = i;
      q.push_back(f);
      q2.push_back(f2);
    }
  }
  int start = 0;
  while(!q2.empty()){
    start = q2[0].second+1;
    bool n = true;
    while(start<a){
      if (b[start].second-b[start].first+q2[0].first.first >= q2[0].first.second){
        count --;
        break;
      }else{
        start++;
      }
    }
    q2.erase(q2.begin());
  }
  cout << count;
}
