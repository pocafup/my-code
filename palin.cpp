#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;
char str[5001];
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >> str[i];
  int ans = 1e8;
  for (int i=0;i<a;i++){
    stack<char> st1,st2;
    int count = 0;
    for (int j=0;j<i;j++) st1.push(str[j]);
    for (int j=i+1;j<a;j++) st2.push(str[j]);
    while(st2.size()&&st1.size()){
      if (st1.top()==st2.top()){
        st1.pop();
        st2.pop();
      }else{
        st2.pop();
        count++;
      }
    }
    count += st1.size()+st2.size();
    ans = min(ans,count);
  }
  cout << ans;
}
