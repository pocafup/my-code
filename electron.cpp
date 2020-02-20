#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  long long a,b;
  cin >> a >> b;
  pair<long long,long long> c[a];
  pair<long long,long long> e[a];
  for (int i=0;i<a;i++){
    cin >> c[i].first >> c[i].second;
    e[i].first = c[i].first;
    e[i].second = c[i].second;
  }
  sort(c,c+a);
  long long d[b];
  long long f[b];
  for (int i=0;i<b;i++){
    d[i] = c[a-b+i-1].second;
    f[i] = c[a-b+i-1].first;
  }
  for (int i=b-1;i>0;i--){
    if (d[i]>d[i-1]) {
      d[i-1] = d[i];
      f[i-1] = f[i];
    }
  }

  for (int i=0;i<a;i++){
    if (e[i].first == f[0] && e[i].second == d[0]){
      cout << i+1;
    }
  }
}
