#include <iostream>
#include <queue>
#include <string>

using namespace std;

void solve(){
  queue<int> xpos;
  xpos.push(0);
  queue<int> ypos;
  ypos.push(0);
  int a;
  cin >> a;
  queue<char> b;
  string c;
  cin >> c;
  for(int i=0;i<a;i++){
    b.push(c[i]);
  }
  while (!b.empty()){
    if (b.front() == 'N'){
      ypos.push(ypos.front()+1);
      ypos.pop();
    }else if(b.front()=='S'){
      ypos.push(ypos.front()-1);
      ypos.pop();
    }else if (b.front()=='W'){
      xpos.push(xpos.front()-1);
      xpos.pop();
    }else{
      xpos.push(xpos.front()+1);
      xpos.pop();
    }
    b.pop();
  }
  cout << xpos.front() << " " << ypos.front() << endl;
}
int main(){
  solve();
}
