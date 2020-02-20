#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int re,re2;
int main(){
  int a,now;
  now = 0;
  cin >> a;
  int maxi = 0;
  pair<int,int> b[a];
  char c;
  for (int i=0;i<a;i++){
    cin >> b[i].first >> c;
    if (c == 'G'){
      b[i].second = 1;
    }
    if (c == 'H'){
      b[i].second = -1;
    }
  }
  sort(b,b+a);
  for (int i=0;i<a;i++){
    re = i;
    int loo = b[i].second;
    for (int j=i+1;j<a;j++){
      loo += b[j].second;
      if (loo == 0){
        re2 = j;
      }
    }
    if (maxi < b[re2].first-b[re].first){

      maxi = b[re2].first-b[re].first;
    }
  }
  for(int i = 0; i < a; ) {
    int res = 1;
    while(i + res < a && b[i].second == b[i + res].second) {
      ++res;
    }
    maxi = max(maxi, b[i + res - 1].first - b[i].first);
    i += res;
  }





  // for (int i=0;i<a;i++){
  //   b[i].second += now;
  //   now = b[i].second;
  // }
  // for (int i=0;i<a;i++){
  //   cout << b[i].first << " " << b[i].second  <<endl;
  // }
  // bool work = false;
  // int res = 0;
  // while (!work){
  //   work = true;
  //   int count = 0;
  //   vector<int> loc;
  //   bool first = true;
  //   for (int i=0;i<a;i++){
  //     if (b[i].second == res){
  //       if (first){
  //         int re3 = b[i].second;
  //       }
  //       bool first = false;
  //
  //       count ++;
  //       loc.push_back(b[i].first);
  //     }
  //   }
  //   if (count > 1){
  //
  //   }
  cout << maxi;
}
