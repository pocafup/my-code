#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec[11];
int per[11];

bool check(int result,int num){
  int re = 0;
  for (int i=0;i<num;i++){
    re+=per[i]*vec[num-1][i];
  }
  return re==result;
}
int main(){
  vec[0].push_back(1);
  int ss = 0;

  for (int i=1;i<12;i++){
    vec[i].push_back(1);
    // cout << vec[i].size();
    for (int j=0;j<vec[i-1].size()-1;j++) vec[i].push_back(vec[i-1][j]+vec[i-1][j+1]);
    vec[i].push_back(1);
  }
  // for (int i=0;i<12;i++){
  //   for (int j=0;j<vec[i].size();j++){
  //     cout << vec[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int a,b; cin >> a >> b;
  for (int i=1;i<=a;i++){
    per[i-1] = i;
  }
  bool ana = false;
  while(!check(b,a) && (!ana || ana && per[0]!=1)){
    next_permutation(per,per+a);
    if (per[0]!=1) ana = true;
  }
  if (ana&& per[0]==1) return 0;
  for (int i=0;i<a;i++) cout << per[i] << " ";
}
