#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main(){
  long long a,b,c,d; cin >> a >> b >> c >> d;
  long long fir[2000];
  long long sec[2000];
  long long fi = -1,se = -1;
  for (long long i=0;i<a;i++){
    long long e,f; cin >> e >> f;
    for (long long j=0;j<e;j++){fir[++fi] = i;}
    for (long long j=0;j<f;j++){sec[++se] = i;}
  }
  for (long long i=0;i<=fi;i++){
    cout << fir[i] << " ";
  }
  cout << endl;
  for (long long i=0;i<=se;i++){
    cout << sec[i] << " ";
  }
  long long ct[1000][1000];
  for (long long j=0; j<=se; j++) {ct[0][j] = j*b;}
  for (long long i=0; i<=fi; i++) {ct[i][0] = i*c;}
  long long n = 0;

  for (long long i=1;i<=fi;i++){
    for (long long j=1;j<=se;j++){
      ct[i][j] = 100000000;
      ct[i][j] = min(ct[i][j],ct[i][j-1]+b);
      ct[i][j] = min(ct[i][j],ct[i-1][j]+c);
      ct[i][j] = min(ct[i][j],ct[i-1][j-1]+d*abs(fir[i]-sec[j]));
    }
  }
  cout << endl;
  // for (long long i=0;i<=fi;i++){
  //   for (long long j=0;j<se;j++){
  //     cout << ct[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << ct[fi][se];
}
