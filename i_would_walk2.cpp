#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
long long n,k,dist[7505],vis[7505];
const long long X = 2019201913;
const long long Y = 2019201949;
const long long MOD = 2019201997;
long long min (int a, int b){return a < b ? a : b;}
long long max (int a, int b){return a > b ? a : b;}

void prims(){
  for (long long i=0;i<n;i++){
    int min_j = 0;
    for (long long j=1;j<=n;j++)if (!vis[j]&&((min_j == 0) || dist[j]<dist[min_j])) min_j = j;
    vis[min_j] = true;
    for (long long j=1;j<=n;j++){
      if (!vis[j]) dist[j] = min(dist[j],(min(j,min_j)*X+max(j,min_j)*Y)%MOD);
    }
  }

}
int main(){
  cin >> n >> k;
  for (int i=0;i<=n;i++) dist[i] = MOD;
  prims();
  sort(dist+1,dist+n+1);
  cout << dist[n-k+1];
}
