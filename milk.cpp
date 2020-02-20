#include <iostream>

using namespace std;

int a,b,c,d;
int e[1000];
int f[1000];
int maxi = 0;
int maxi2 = 0;
int recur(int n, int in, int fir,int sec,int thi,int z){
  if (n>a-1){
    if (maxi2<z){
      maxi2 = z;
    }
  }else if (in<e[n]){
    recur(n+1,in,fir,sec,thi,z+fir);
  }else if (in>f[n]){
    recur(n+1,in,fir,sec,thi,z+thi);
  }else{
    recur(n+1,in,fir,sec,thi,z+sec);
  }

}
int main(){
  cin >> a >> b >> c >> d;
  memset(e,0,sizeof(e));
  memset(f,0,sizeof(f));

  for(int i=0;i<a;i++){
    cin >> e[i] >> f[i];
    if (f[i]>maxi){
      maxi = f[i];
    }
  }
  for (int i=0;i<maxi;i++){
    recur(0,i,b,c,d,0);
  }
  cout << maxi2;
}
