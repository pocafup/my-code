#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue <long long> se;
long long a;
pair<long long,long long> pos[100001];
int main(){
  cin >> a;
  for (long long i=0;i<a;i++) {
    cin >> pos[i].first >> pos[i].second;
    pos[i].second = -pos[i].second;
  }
  sort(pos,pos+a);

  for (long long i=0;i<a;i++){
    if (se.size()<pos[i].first){
      se.push(pos[i].second);
    }else{
      if(se.top()>pos[i].second){
        se.pop();
        se.push(pos[i].second);
      }
    }
  }
  long long ans = 0;
  while(!se.empty()){
    ans -= se.top();
    se.pop();

  }
  cout << ans;
}
