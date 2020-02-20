#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
priority_queue<int> pq;
int pos[100001];
int go;
int main(){
  int a; cin >> a;
  int num = 0;
  int go = 0;
  bool n = false;
  for (int i=0;i<a;i++) {cin >>pos[i];}
  sort(pos,pos+a);
  int pa = 0;
  for (int i=2;i<a;i++){
    if (pos[i-1]-1==pos[i-2]&& pos[i]==pos[i-1]) {cout << "cslnb";exit(0);}
  }
  for (int i=1;i<a;i++){if (pos[i] == pos[i-1]) pa++;}
  if (pa>1) {cout << "cslnb";exit(0);}
  for (int i=1;i<a;i++){
    if (pos[i]==pos[i-1]){
      if (i==1&&pos[i]==0) {cout << "cslnb";exit(0);}
      else {
        pos[i-1]--;
        if (pos[i-1]==go)go++;
        num=(num+1)%2;
      }
    }
    else if (pos[i-1]==pos[i] && pos[i-1]!=go){
      pos[i-1]--;
      if (pos[i-1]==go) go++;
      num = (num+1)%2;
    }
  }
  for (int i=0;i<a;i++){
    if (pos[i]>=go) pq.push(-pos[i]);
  }
  // cout << go << endl;
  while(!pq.empty()){
    num = (num+(-pq.top()-go))%2;
    pq.pop();
    go++;
  }
  if (num) cout << "sjfnb";
  else cout << "cslnb";
}
