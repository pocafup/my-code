#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

long long num[100005];
int main(){
  long long a; cin >> a;
  for (long long i=0;i<a;i++) cin >> num[i];
  stack<long long> st;
  st.push(0);
  long long ans = 0;
  for (long long i=0;i<a;i++){
    if (st.top()<num[i]){
      st.push(num[i]);
    }else if(st.top()>num[i]){
      long long z = st.top();
      while(st.top()>num[i]){
        st.pop();
      }
      ans += z-num[i];
      st.push(num[i]);
    }
  }
  ans += st.top();
  cout << ans;
}
