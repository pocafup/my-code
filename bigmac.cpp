#include <iostream>
#include <algorithm>

using namespace std;

long long a,b,d,e;
double c;
double N[2001][2];
pair<pair<int,int>,double> M[25001];

int main(){
  cin >> a >> b >> c >> d >> e;
  d--;e--;
  for (int i=0;i<b;i++) {

    cin >> M[i].first.first >> M[i].first.second >> M[i].second;
    M[i].first.first--; M[i].first.second--;
  }
  for (int i=0;i<a;i++) {N[i][0] = 1e18;N[i][1] = 1e18;}
  bool update = true;
  double loop = 0;
  N[d][0] = c;
  while(update){
    update = false;

    for (int i=0;i<a;i++){
      cout << N[i][0] << " ";
    }
    cout <<endl;
    for (int i=0;i<b;i++){
      if(N[M[i].first.second][1]>N[M[i].first.first][0]*M[i].second){
        N[M[i].first.second][1] = N[M[i].first.first][0]*M[i].second;
        update = true;
      }
    }
    for (int i=0;i<a;i++){
      N[i][0] = min(N[i][0],N[i][1]);
    }
    loop++;
    if (loop>b) {cout << 0; exit(0);}
  }
  cout << N[e][0];
}
