#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;
int n;
int pos[100001];
priority_queue<int> pq;
int main(){
  // ifstream cin ("herding.in");
  // ofstream cout("herding.out");
  cin >> n;
  for (int i=0;i<n;i++) {cin >> pos[i];pq.push(pos[i]-i);}
  int prev = pq.top(),consec = 1;
  pq.pop();
  int maxi = 0,mini = 1e9;
  while(!pq.empty()){
    if (pq.top()!=prev){
      mini = min(mini,consec);
      prev = pq.top();
      consec = 1;

    }else {consec++;maxi = max(maxi,consec);}

    pq.pop();
  }
  maxi = max(maxi,consec);
  if (mini ==1e9) mini = n;
  else  mini = min(mini,consec);

  cout << n-maxi << endl << n-mini;
}
