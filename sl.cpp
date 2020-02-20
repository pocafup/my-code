#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int solution = 0;
  int n,m;
  cin>>n>>m;
  int road[101] = {};
  int bessie[101] = {};

  int pos = 0;

  for(int i=0;i<n;++i){
      int a,b; cin >> a >> b;
      for(int j=pos;j<pos+a;++j){
        road[j] = b;
      }
      pos+=a;
  }
  pos = 0;
  for(int i=0;i<m;++i){
      int a,b;cin >> a >> b;
      for(int j=pos;j<pos+a;++j){
        bessie[j] = b;
      }
      pos += a;
  }

  for (int i=0;i<100;i++){
    solution = max(solution,road[i]-bessie[i]);
  }
  cout << solution;
}
