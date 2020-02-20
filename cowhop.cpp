#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
long long d[751][751], e[751][751];
int main(){
  ifstream cin("aabb.in");
  ofstream cout("aabb.out");
  long long a,b,c;
  cin >> a >> b >> c;

  for (long long i=0;i<a;i++){
    for (long long j=0;j<b;j++){
      cin >> d[i][j];
    }
  }
  e[0][0] = 1;
  for (long long i=1;i<a;i++){
    for (long long j=1;j<b;j++){
      for (long long k=i-1;k>=0;k--){
        for (long long kk=j-1;kk>=0;kk--){
          if (d[i][j]!=d[k][kk] && !(k==0 and kk!= 0) && !(k!=0 and kk == 0)){
            e[i][j] += e[k][kk] %1000000007;
            e[i][j] = e[i][j] %1000000007;
          }
        }
      }
      e[i][j] = e[i][j]% 1000000007;
    }
  }
  cout << e[a-1][b-1] % 1000000007;
  return 0;
}
