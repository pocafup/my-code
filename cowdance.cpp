#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;

int num[10001];

int main(){
  // ifstream cin("cowdance.in");
  // ofstream cout("cowdance.out");
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> num[i];
  sort(num,num+a);

  int right = 1e4,left = 1;
  while(left!=right-1){
    int mid = (right+left)/2;
    int pos = 0;
    priority_queue<int> q;
    while(pos!=a){
      if (q.size()<mid) q.push(-num[pos]);
      else {
        int qt = q.top();
        q.pop();
        if (-qt>num[pos]){
          q.push(qt+q.top());
          q.push(num[pos]);

        }
        else{
          q.push()
        }
        q.push(-num[pos]+q.top());
      }
      pos++;
    }
    int maxi = 0;
    while(!q.empty()){ maxi = max(-q.top(),maxi);q.pop();}
    if (maxi<=b) right = mid;
    else left = mid;
  }
  int pos = 0;
  priority_queue<int> q;
  while(pos!=a){
    if (q.size()<left) q.push(-num[pos]);
    else {
      q.push(-num[pos]+q.top());
      q.pop();
    }
    pos++;
  }
  int maxi = 0;
  while(!q.empty()){ maxi = max(-q.top(),maxi);q.pop();}
  cout << maxi << " " << left << " " << right<< endl;
  if (maxi<=b) cout << left;
  else cout << right;
}
