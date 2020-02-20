#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define INF 2*1e18;
typedef pair<long long,long long> pp;
long long bsd[40001];
long long esd[40001];
long long bkd[40001];
vector<long long> go[40001];
int main(){
  long long a,b,c,d,e; cin >> a >> b >> c >> d >> e;
  for (long long i=0;i<40001;i++){bsd[i]=INF;esd[i]=INF;bkd[i]=INF;}
  for (long long i=0;i<e;i++){
    long long f,g; cin >> f >> g;
    f--;g--;
    go[f].push_back(g);
    go[g].push_back(f);
  }
  bsd[0] = 0;esd[1] = 0;bkd[d-1]=0;

  queue<pp> qb,qs,bk;
  for (long long i=0;i<go[0].size();i++)qb.push(make_pair(go[0][i],a));
  for (long long i=0;i<go[1].size();i++)qs.push(make_pair(go[1][i],b));
  for (long long i=0;i<go[d-1].size();i++)bk.push(make_pair(go[d-1][i],c));

  while(!qb.empty()){
    long long qf = qb.front().first;
    long long qd = qb.front().second;
    qb.pop();
    if (qd<bsd[qf]){
      bsd[qf] = qd;
      for (long long i=0;i<go[qf].size();i++){
        qb.push(make_pair(go[qf][i],qd+a));

      }
    }

  }
  while(!qs.empty()){
    long long qf = qs.front().first;
    long long qd = qs.front().second;
    qs.pop();
    if (qd<esd[qf]){
      esd[qf] = qd;
      for (long long i=0;i<go[qf].size();i++){
        qs.push(make_pair(go[qf][i],qd+b));

      }
    }
  }
  // for (long long i=0;i<d;i++) {
  //   cout << bsd[i] << " " << esd[i] << endl;
  // }
  while(!bk.empty()){
    long long qf = bk.front().first;
    long long qd = bk.front().second;
    bk.pop();
    if (qd<bkd[qf]){
      bkd[qf] = qd;
      for (long long i=0;i<go[qf].size();i++){
        bk.push(make_pair(go[qf][i],qd+c));

      }
    }
  }
  long long mini = 1e18;
  for (long long i=0;i<d;i++) {
    cout << "        " << bkd[i] << " " << bsd[i] << " " << esd[i] << endl;
    mini = min(mini,bkd[i]+bsd[i]+esd[i]);
  }

  cout << mini;
}
