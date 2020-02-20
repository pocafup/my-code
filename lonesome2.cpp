#include <iostream>
#include <algorithm>
#include <stack>
#include <math.h>
#include <vector>
using namespace std;
#define pp pair<int,int>
pp pt[5001];
pair<pp,int> res[5001];

bool ccw(pp a, pp b, pp c) {
    return (b.first - a.first) * (c.second - a.second)
         > (b.second - a.second) * (c.first - a.first);
}
bool sorted(pair<pp,int> a, pair<pp,int> b){
  return a.first<b.first;
}
double dis(pp aa, pp bb){
  return sqrt((aa.first-bb.first)*(aa.first-bb.first)+(aa.second-bb.second)*(aa.second-bb.second));
}
int main(){
  int a; cin >> a;
  vector<int> vec;
  for (int i=0;i<a;i++) {
    cin >> pt[i].first >> pt[i].second;
    res[i] = make_pair(pt[i],i+1);
  }


  sort(pt,pt+a);
  sort(res,res+a,sorted);
  stack<int> st;
  st.push(0);
  int curr = 1,pos = 2;
  while(pos!=a){
    while(st.size()>1){
      if (ccw(pt[st.top()],pt[curr],pt[pos])){
        curr = st.top();
        st.pop();
      }else break;
    }
    if (ccw(pt[st.top()],pt[curr],pt[pos])) curr = pos;
    else {
      st.push(curr);
      curr = pos;
    }
    pos++;
  }
  double ans = 0;
  while(!st.empty()){
    vec.push_back(curr);
    curr = st.top();
    st.pop();
  }
  vec.push_back(curr);
  st.push(0);
  curr = 1,pos = 2;
  while(pos!=a){
    while(st.size()>1){
      if (!ccw(pt[st.top()],pt[curr],pt[pos])){
        curr = st.top();
        st.pop();
      }else break;
    }
    if (!ccw(pt[st.top()],pt[curr],pt[pos])) curr = pos;
    else {
      st.push(curr);
      curr = pos;
    }
    pos++;
  }
  while(!st.empty()){
    vec.push_back(curr);
    curr = st.top();
    st.pop();
  }
  vec.push_back(curr);
  pp re;
  for (int i=0;i<vec.size();i++){
    for (int j=i+1;j<vec.size();j++){
      if (dis(pt[vec[i]],pt[vec[j]])>ans){
        ans = dis(pt[vec[i]],pt[vec[j]]);
        re = make_pair(res[vec[i]].second,res[vec[j]].second);
        if (re.first>re.second) swap(re.first,re.second);
      }
    }
  }
  cout << re.first << " " << re.second;
}
