#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
#define pp pair<long long,long long>
long long n;
pp pos[100001];
long long fat[800005];
struct node{
  long long from,to,dis;
}edge[800005];
long long dist(pp a, pp b){
  return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
long long tot = 0;
void add(long long a, long long b){
  edge[++tot].from = a;
  edge[tot].to = b;
  edge[tot].dis = dist(pos[a],pos[b]);
}
long long father(long long x){
	if(fat[x]!=x)
	return father(fat[x]);
	else return x;
}
void Union(long long x, long long y){
  fat[father(y)] = father(x);
}
bool sorted(node aa, node bb){
  return aa.dis < bb.dis;
}
long long road = 0, ans = 0;
int main(){
  ifstream cin ("moocast.in");
  ofstream cout ("moocast.out");
  cin >> n;
  for (long long i=0;i<n;i++) cin >> pos[i].first >> pos[i].second;
  for (long long i=0;i<n;i++){
    for (long long j=i+1;j<n;j++){
      add(i,j);
      add(j,i);
    }
  }
  sort(edge,edge+tot,sorted);
  for (long long i=0;i<n;i++) fat[i] = i;
  for (long long i=0;i<tot;i++){
    if (road == n-1) break;
    if (fat[father(edge[i].from)]!=fat[father(edge[i].to)]){
      ans = max(ans,edge[i].dis);

      Union(edge[i].from,edge[i].to);
      road++;
    }
  }
  cout << ans;
}
