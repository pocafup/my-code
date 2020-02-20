#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int,int> cost[50001];
priority_queue<int > pq;
int main(){
  int a,b,c; cin >> a >> b >> c;
  priority_queue<pair<int,int> > temp;
  for (int i=0;i<a;i++) {
    cin >> cost[i].first >> cost[i].second;
    temp.push(make_pair(-cost[i].first,-cost[i].second));
  }
  //sort(cost,cost+a);

  int re = 0;
  int pos = 0;
  priority_queue<int> q2;
  while(re-temp.top().first<=c){
    re-=temp.top().first;
    pq.push(-temp.top().first);
    temp.pop();
  }
  while(!temp.empty()){
    q2.push(temp.top().second);
    temp.pop();
  }
  // while(!pq.empty()){
  //   cout << pq.top() << " ";
  //   pq.pop();
  // }
  bool update = false;
  while(pq.top()>-q2.top() && b>0){
    update = false;
    while(re-q2.top()<=c && b>0){
      update = true;
      re-=q2.top();
      pq.push(-q2.top());
      q2.pop();
      b--;
    }
    if (!update){
      re -= pq.top();
      pq.pop();
    }


  }
  cout << pq.size();
}
