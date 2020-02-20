#include <iostream>
#include <algorithm>

using namespace std;

pair<long long,long long> pos[100001];
long long prefix[100001];
int prefixmax[100001][2];
int main(){
  long long a; cin >> a;
  for (long long i=0;i<a;i++){
    long long b; char d; cin >> b >> d;
    if (d == 'G') pos[i] = make_pair(b,1);
    else pos[i] = make_pair(b,0);
  }
  sort(pos,pos+a);
  for (int i=0;i<a;i++) cout << pos[i].first << " " << pos[i].second << endl;
  long long right = 1;
  long long left = 0;
  long long ans = 0;
  if (pos[0].second==0) prefix[0] = -1;
  else prefix[0] = 1;
  prefixmax[0][pos[0].second] = 0;
  for (long long i=100000;i<a+100000;i++){
    if (pos[i].second == 0) prefix[i] = prefix[i-1]-1;
    else prefix[i] = prefix[i-1]+1;
    prefixmax[prefix[i]][pos[i].second] = pos[i].first;
  }
  for (int i=0;i<a;i++){
    int plus = pos[i].second ? -1:1;
    if (pos[i].second == 1){
      if(prefixmax[prefix[i]-1][])
    }
  }





  cout << ans;
}
