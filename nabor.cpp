#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<unsigned long long,unsigned long long> pos[100001];
bool vis[100001];
unsigned long long dis(pair<unsigned long long,unsigned long long> aa, pair<unsigned long long,unsigned long long> bb){
  return (aa.first-bb.first)*(aa.first-bb.first)+(aa.second-bb.second)*(aa.second-bb.second);
}
bool sorted(pair<unsigned long long,unsigned long long> aa,pair<unsigned long long,unsigned long long> bb){
  if (aa.first!=bb.first) return aa.first<bb.first;
  return aa.second<bb.second;
}
vector<pair<int,int> > remem;
int main(){
  unsigned long long a,b; cin >> a >> b;
  for (unsigned long long i=0;i<a;i++) cin >> pos[i].first >> pos[i].second;
  unsigned long long group = 0;
  unsigned long long size = 1;
  sort(pos,pos+a,sorted);
  // for (unsigned long long i=0;i<a-1;i++) cout << pos[i].first<< "    " << pos[i].second<< endl;
  // for (unsigned long long i=0;i<a;i++) {
  //   for(int j=i+1;j<a;j++){
  //     cout << "dis from " << i << " to " << j << " is " << dis(pos[i],pos[j]) << endl;
  //
  //   }
  // }

  queue<pair<unsigned long long,unsigned long long> > q;
  for (unsigned long long i=0;i<a;i++){
    bool update = false;
    for (unsigned long long j=i;j<a;j++){
      if (!vis[j] && !vis[i] && dis(pos[i],pos[j])<b && i!=j){
        vector<pair<int,int> > te;
        swap(te,remem);
        update = true;
        vis[j] = true;
        vis[i] = true;
        q.push(pos[i]);
        q.push(pos[j]);
        remem.push_back(pos[i]);
        remem.push_back(pos[j]);
        unsigned long long temp = 2;
        while(!q.empty()){
          unsigned long long qf = q.front().first;
          unsigned long long qs = q.front().second;
          pair<unsigned long long,unsigned long long> qfr = q.front();
          q.pop();
          for (unsigned long long k=0;k<a;k++){
            if (!vis[k]){
              if (dis(pos[k],qfr)<b && dis(pos[k],qfr)!=0){
                vis[k] = true;
                q.push(pos[k]);
                temp++;
                remem.push_back(pos[k]);
              }
            }

            if ((qf-pos[k].first)*(qf-pos[k].first)>=b && qf<pos[k].first) break;
          }
        }
        group++;
        size = max(size,temp);
        if (temp == 22){
          for (int l=0;l<remem.size();l++){
            cout << remem[l].first << " " << remem[l].second << endl;
          }
        }
      }
    }
    if (!update && !vis[i]) group++;
  }
  cout << group << " " << size;
}
