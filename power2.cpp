#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>

using namespace std;
double bfs[1000][1000];
int main(){
  int a,b; cin >> a >> b;
  double cap; cin >> cap;
  pair<int,int> re[a];
  for (int i=0;i<a;i++) cin >> re[i].first >> re[i].second;
  vector<int> vec[a];
  for (int i=0;i<b;i++){
    int c,d; cin >> c >> d;
    vec[c].push_back(d);
    vec[d].push_back(c);
  }

  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      bool n = true;

      for (int k=0;k<vec[i].size();k++){
        if (vec[i][k] == j){ n = false;bfs[i][j] = 0;
        }else bfs[i][j] = sqrt(abs(re[i].first-re[j].first))+sqrt(abs(re[i].second-re[j].second));
      }
      if (i == 0 && n == false) {cout<< i << " " << j << endl;}
    }
  }`
  `
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout << bfs[i][j] << " ";
    }
    cout << endl;
  }
}
