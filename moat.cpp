#include <iostream>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <limits>
#include <stdio.h>


using namespace std;
#define pp pair<int,int>
pp pt[5001];
bool ccw(pp a, pp b, pp c) {
    return (b.first - a.first) * (c.second - a.second)
         > (b.second - a.second) * (c.first - a.first);
}
double dis(pp aa, pp bb){
  return sqrt((aa.first-bb.first)*(aa.first-bb.first)+(aa.second-bb.second)*(aa.second-bb.second));
}
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >> pt[i].first >> pt[i].second;
  sort(pt,pt+a);
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
  sort()
  double ans = 0;
  // while(!st.empty()){
  //   ans += dis(pt[st.top()],pt[curr]);
  //   curr = st.top();
  //   st.pop();
  // }
  // st.push(0);
  // curr = 1,pos = 2;
  // while(pos!=a){
  //   while(st.size()>1){
  //     if (!ccw(pt[st.top()],pt[curr],pt[pos])){
  //       curr = st.top();
  //       st.pop();
  //     }else break;
  //   }
  //   if (!ccw(pt[st.top()],pt[curr],pt[pos])) curr = pos;
  //   else {
  //     st.push(curr);
  //     curr = pos;
  //   }
  //   pos++;
  // }
  while(!st.empty()){
    ans += dis(pt[st.top()],pt[curr]);
    curr = st.top();
    st.pop();
  }

  printf("%.2lf",ans);
}
