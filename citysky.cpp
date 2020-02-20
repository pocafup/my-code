#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int pos[50001];
int main(){
  int a,b,ans=0; cin >> a >> b;
  for (int i=0;i<a;i++){
    int c,d; cin >> c >> d; pos[i] = d;
  }
  stack<int> s; s.push(0);
  for (int i=0;i<a;i++){
    while(pos[i]<s.top()) s.pop();
    if (pos[i]>s.top()){
      s.push(pos[i]);
      ans++;
    }
  }
  cout << ans;
}
