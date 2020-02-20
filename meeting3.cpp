#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Cow{
  long long pos,weight, direction;
}cow[100005];

long long n,m,sum = 0,t = 1e9,ans=0;

bool sorted(Cow a, Cow b){
  return a.pos<b.pos;
}
queue<long long> q;
void go_to_end(){
  for (long long i=0;i<n;i++){
    cow[i].pos +=cow[i].direction*t;
  }
}
int main(){
  cin >> n >> m;
  for (long long i=0;i<n;i++){
    cin >> cow[i].pos >> cow[i].weight >> cow[i].direction;
    sum+=cow[i].weight;
  }
  sum/=2;
  sort(cow,cow+n,sorted);
  long long keep = 0;
  for (long long i=0;i<n;i++){
    if (cow[i].direction == -1) keep+=cow[i].weight;
    if (keep>=sum) {t = min(t,cow[i].pos);cout << "fafsadf" << cow[i].pos << endl;break;}

  }
  keep = 0;
  for (long long i=n-1;i>=0;i--){
    if (cow[i].direction==1) keep+= cow[i].weight;
    if (keep>=sum) {t= min(t,m-cow[i].pos);cout << "kasdf" << cow[i].pos << endl;break;}
  }
  // go_to_end();
  // for (long long i=0;i<n;i++) cout << cow[i].pos << " ";
  // cout << endl;
  cout << t << endl;
  // sort(cow,cow+n,sorted);
  // while (sz(rig) && rig.front()+2*t < x[i]) rig.pop();
  t = 292305790;
  cout << t << endl;
  for (long long i=0;i<n;i++){

    if (cow[i].direction==-1){
      while(q.size() && q.front()+2*t < cow[i].pos) q.pop();
      ans += q.size();
    }else q.push(cow[i].pos);
    // if (se.size()) while(se.front()>cow[i].pos) {se.pop_front(); if (se.empty()) break;}
    // if (cow[i].direction==1) se.push_back(cow[i].direction);
    // ans += se.size()*2;
  }
  cout << ans;
}
