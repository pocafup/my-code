#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[21];
long long a,b;

long long fac[22];
long long pos[21];

long long check(){
  memset(pos,0,sizeof(pos));
  for (long long j=1;j<=a;j++){
    cin >> pos[j];
  }
  long long temp = 0;
  for (long long i=1;i<=a;i++){
    long long count = 0;
    for (long long j=i+1;j<=a;j++){
      if (pos[i]>pos[j]) count++;
    }
    temp += count*fac[a-i];
  }
  return temp+1;
}

void check2(long long dd){
  dd--;
  memset(visited,0,sizeof(visited));

  for (long long i=1;i<=a;i++){
    long long po = dd/fac[a-i];
    //cout << endl << fac[a-i] << " " << po << endl;

    for (long long j=1;j<=a;j++){
      if (!visited[j] && po == 0) {
        visited[j] = true;
        cout << j << " ";
        break;
      }
      else if (!visited[j]) po--;
    }
    dd%=fac[a-i];


  }
  cout << endl;
}

int main(){
  fac[0] = 1;
  for (long long i=1;i<=20;i++){
    fac[i] = fac[i-1]*i;
  }
  cin >> a >> b;
  for (long long i=0;i<b;i++){
    char c; cin >> c;
    if(c=='Q'){
      // memset(pos,0,sizeof(pos));
      // for (long long j=1;j<=a;j++){
      //   cin >> pos[j];
      // }
      cout << check() << endl;
    }else if (c=='P'){
      long long d; cin >> d;
      //memset(visited,0,sizeof(visited));
      check2(d);
    }
  }
}
