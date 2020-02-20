#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  pair<int,int> tasty[b];
  for (int i=0;i<b;i++){
    cin >> tasty[i].first >> tasty[i].second;
  }
  int out = 0;
  int re = tasty[b-1].second;
  int num = tasty[b-1].first;
  for (int i=b-1;i>=0;i--){
    if (tasty[i].second>re){
      out += re*(num-tasty[i].first);
      re = tasty[i].second;
      num = tasty[i].first;
    }
  }
  out += re*num;
  cout << out*(c-d);
}
