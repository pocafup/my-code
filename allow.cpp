#include <iostream>
#include <algorithm>

using namespace std;
#define INF 200000000;
pair<int,int> n[20];
int prefix[20];
bool sorted(pair<int,int> aa, pair<int,int> bb){
  return aa.first > bb.first;
}
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> n[i].first >> n[i].second;
  sort(n,n+a,sorted);
  for (int i=0;i<a;i++){
    int cc = 1;
    while(n[i].first*cc<b){
      cc++;
    }
    prefix[i] = cc*n[i].first;
  }
  int begin = 0;
  int ans = 0;
  while(n[begin].first>b){
    ans += n[begin].second;
    n[begin].second = 0;
    begin++;
  }
  int work = true;
  int top = a-1;
  while(work){
    int greed = 0;
    vector<int> vec;
    for (int i=begin;i<top;i++){
      int ee = 0;
      while(greed+n[i].first<=b && n[i].second-ee>=0){
        greed+= n[i].first;
        ee++;
      }
      vec.push_back(ee);
    }
    int maxi = 0;
    for (int i=0;i<vec.size();i++){
      maxi = max(vec[i],maxi);
    }
    for (int j=0;j<vec.size();j++){
      if (vec[i]!=0){

      }
    }
  }
}
