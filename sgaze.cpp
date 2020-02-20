#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int sorted(pair<int,int> aa,pair<int,int> bb){
  return aa.second<bb.second;
}
int main(){
  int a; cin >> a;
  pair<int,int> b[a];
  int c,d;
  for (int i=0;i<a;i++){
    cin >> c >> d;
    b[i] = make_pair(c,d);
  }
  sort(b,b+a,sorted);
  // for (int i=0;i<a;i++){
  //   cout << b[i].first << " " << b[i].second << endl;
  // }
  int pos = 1;
  int count = 1;
  int pos2 = 0;
  while (pos<a){
    if (b[pos].first>=b[pos2].second){
      count ++;
      pos2 = pos;
    }
    pos ++;
  }
  cout << count;
}
