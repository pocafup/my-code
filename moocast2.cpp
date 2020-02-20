#include <iostream>
#include <algorithm>

using namespace std;
#define INF 200000000;

long long dis(pair<long long,long long> aa, pair<long long,long long> bb){
  return (aa.first-bb.first)*(aa.first-bb.first)+(aa.second-bb.second)*(aa.second-bb.second);
}
pair<int,int> pos[1001];
int dist[1001][1001];
int main(){
  int a;cin >> a;

  for (int i=0;i<a;i++) cin >> pos[i].first >> pos[i].second;
  for (int i=0;i<a;i++)
    for (int j=0;j<a;j++)
      dist[i][j] = 20000000;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      dist[i][j] = min(dist[i][j],dis(pos[i],pos[j]));
      //dist[i][j] = min(dist[i][j];)
    }
  }
  long long maxi = 0;
  for (long long i=0;i<a;i++) maxi = max(dist[a-1][i],maxi);
  cout << maxi;
}
