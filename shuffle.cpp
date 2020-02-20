#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

queue<int> que;

int main(){
  int a,count = 0;
  cin >> a;
  int b[a];
  int re[a];
  memset(b,0,sizeof(b));
  for (int i=0;i<a;i++){
    int c;
    cin >> c;
    b[c-1]++;
    re[i] = c;
  }
  for (int i=0;i<a;i++){
    if (b[i] == 0){
      que.push(i);
    }
  }
  while (que.size()){
    b[re[que.front()]-1]--;

    if (b[re[que.front()]-1] == 0){
      que.push(re[que.front()]-1);
    }
    que.pop();
  }
  for (int i=0;i<a;i++){
    if (b[i] != 0){
      count ++;
    }
  }
  cout << count;
}
