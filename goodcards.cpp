#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  queue<int> q;
  vector<int> good;
  for(int i=0;i<b;i++){
    q.push(i+1);
  }
  while(!q.empty()){
    for (int i=0;i<a-1;i++){
      q.pop();

      for (int j=0;j<c;j++){
        q.push(q.front());
        q.pop();
      }
    }
    good.push_back(q.front());
    q.pop();

    for (int i=0;i<c;i++){
      q.push(q.front());
      q.pop();
    }
  }
  sort(good.begin(),good.end());
  for (int i=0;i<good.size();i++){
    cout << good[i] << endl;
  }
}
