#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> cd;
int main(){
  int a,b;
  cin >> a >> b;
  int c[a];
  for (int i=0;i<a;i++){
    cin >> c[i];
    c[i] = c[i]*2;
  }
  sort(c,c+a);


  for (int i=1; i<a-1;i++){
    int e,va,vb;
    e = min(i,a-i-1);
    va = c[i-1];
    vb = c[i+1];
    bool n = true;
    for (int j=1;j<e+1;j++){
      if (not(abs(va-c[i]) == abs(vb-c[i]))){
        n = false;
      }
      if (i-j>=0 && i+j<=a-1){
        va = c[i-j-1];
        vb = c[i+j+1];
      }
    }
    if (n){
      cd.push_back(c[i]);
    }
  }
  for (int i=0;i<a-1;i++){
    int f,vc,vd,dis,res;
    f = min(i,a-i);
    vc = c[i];
    vd = c[i+1];
    dis = (vc+vd)/2;
    res = 1;
    bool e = true;
    while (e){
      if (abs(vc-dis) == abs(vd-dis)){
        if (i-res < 0 or i+res+1 >=a){

          break;
        }else{
          vc = c[i-res];
          vd = c[i+1+res];
          res++;
        }
      }else{
        e = false;
      }
    }
    if (e){
      cd.push_back(dis);
    }
  }
  cout << cd.size();
}
