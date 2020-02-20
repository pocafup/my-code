/*
ID:dx424391
PROG: lemonade
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

int pos[100001];
bool sorted(int aa,int bb){
  return aa>bb;
}
int main(){
  ofstream cout("lemonade.out");
  ifstream cin ("lemonade.in");
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >> pos[i];
  sort(pos,pos+a,sorted);
  stack<int> st;
  for (int i=0;i<a;i++){
    if (pos[i]>=st.size()) {
      st.push(pos[i]);
      //cout << st.size();
    }
    else{
      cout << st.size();
      break;
    }
    if(i==a-1) cout << st.size();
  }

}
