#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
#define INF 200000000;

int n[10000];
int p[10000];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> n[i];
  for (int i=0;i<b;i++) {
    int c,d; cin >> c >> d;
    p[c]++;
    p[d]--;
  }
  // for (int i=0;i<b;i++){
  //   cout << p[i] << " ";
  // }
  // cout << endl;
  priority_queue<int> q1;
  priority_queue<int> q2;
  // cout << endl;
  for (int i=1;i<=a;i++){
    if (p[i]<0){
      for (int j=0;j<abs(p[i]);j++){
        q2.push(n[i-1]);
      }
    }else if (p[i]>0){
      for (int j=0;j<abs(p[i]);j++){
        q1.push(n[i-1]);
      }
    }
  }
  int maxi = 0;
  while(!q1.empty() && !q2.empty()){
    // cout << q1.top() << " " << q2.top() << endl;
    maxi += abs(q1.top()-q2.top());
    q1.pop();
    q2.pop();
  }
  cout << maxi;
}
