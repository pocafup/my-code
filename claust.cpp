#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a; cin >> a;
  pair<int,int> b[a];
  for (int i=0;i<a;i++){
    cin >> b[i].first >> b[i].second;
  }
  int d = 0, e=0;
  long long bb = 100000000;
  for (int i=0;i<a-1;i++){
    for (int j=i+1;j<a;j++){
      if (abs(b[i].first-b[j].first)*abs(b[i].first-b[j].first)+abs(b[i].second-b[j].second)*abs(b[i].second-b[j].second)<bb){
        bb = abs(b[i].first-b[j].first)*abs(b[i].first-b[j].first)+abs(b[i].second-b[j].second)*abs(b[i].second-b[j].second);
        d = i+1;
        e = j+1;
      }
    }
  }
  cout << d << " " << e;
}
