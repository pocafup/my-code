#include <iostream>
#include <algorithm>

using namespace std;
int n,ans = 0;
string s;
int check_odd(int pos){
  int ct = 1, le = pos-1,ri = pos+1;
  while(le>=0 && ri<n){
    if(s[le]==s[ri]) {ct+=2;le--;ri++;}
    else break;
  }
  return ct;
}
int check_even(int pos){
  if (s[pos]!=s[pos+1]) return 0;
  int ct = 2, le = pos-1, ri = pos+2;
  while(le>=0 && ri<n){
    if(s[le]==s[ri]) {ct+=2;le--;ri++;}
    else break;
  }
  return ct;
}
int main(){
  cin >> n >> s;
  for (int i=0;i<n-1;i++){
    ans = max(ans,max(check_odd(i),check_even(i)));
  }
  cout << n-ans;
}
