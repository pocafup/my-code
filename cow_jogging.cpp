#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
int n,m,k;
vector<int> ans,tmp;
vector<pp> adj[10005];
priority_queue<int> pq[10005];
int min(int a, int b){return a<b?a:b;}
int main(){
  cin >> n >> m >>k;
  for (int i=0;i<m;i++){
    int a,b,c; cin >> a >> b >> c;
    // add(a,b,c);
    adj[a].push_back(make_pair(b,c));
  }
  queue<pp> q;
  q.push(make_pair(n,0));
  while(!q.empty()){
    int qf = q.front().f, qs = q.front().s;q.pop();
    for (pp i : adj[qf]){
      if (pq[i.f].size()<k) {q.push(make_pair(i.f,qs+i.s)); pq[i.f].push(qs+i.s);}
      else {
        if (pq[i.f].top()> qs+i.s){
          q.push(make_pair(i.f,qs+i.s));
          pq[i.f].pop();
          pq[i.f].push(qs+i.s);
        }
      }
    }
  }

  while(pq[1].size()) {tmp.push_back(pq[1].top());pq[1].pop();}
  sort(tmp.begin(),tmp.end());
  for (int i=0;i<min(k,tmp.size());i++) cout << tmp[i] << endl;
  if (tmp.size()<k) for (int i=0;i<(k-tmp.size());i++) cout << -1 << endl;
}
