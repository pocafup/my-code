#include <iostream>
#include <algorithm>

using namespace std;


int main(){
  long n,a,b,c,d,e,f,g,h,m;
  long mini = 0;
  long mini2 = 0;
  long weight = 0;
  long weight2 = 0;
  cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m;
  for (int i=0;i<3*n;i++){
    if ((e*i*i*i*i*i+f*i*i*i+g)%h>mini){
      mini2 = mini;
      weight2 = weight;
      mini = (e*i*i*i*i*i+f*i*i*i+g)%h;
      weight = (a*i*i*i*i*i+b*i*i+c)%d%m;
      cout << mini << " " << weight << endl;

    }else if((e*i*i*i*i*i+f*i*i*i+g)%h==mini){
      if ((a*i*i*i*i*i+b*i*i+c)%d%m>weight){
        mini2 = mini;
        weight2 = weight;
        mini = (e*i*i*i*i*i+f*i*i*i+g)%h;
        weight = (a*i*i*i*i*i+b*i*i+c)%d%m;
        cout << mini << " " << weight << endl;

    }else if((e*i*i*i*i*i+f*i*i*i+g)%h>mini2){

      mini2 = (e*i*i*i*i*i+f*i*i*i+g)%h;
      weight2 = (a*i*i*i*i*i+b*i*i+c)%d%m;
      cout << mini << " " << weight << endl;
    }
    }else if((e*i*i*i*i*i+f*i*i*i+g)%h==mini2){
      if ((a*i*i*i*i*i+b*i*i+c)%d%m>weight2){
        mini2 = (e*i*i*i*i*i+f*i*i*i+g)%h;
        weight2 = (a*i*i*i*i*i+b*i*i+c)%d%m;
        cout << mini << " " << weight << endl;

      }
    }
  }
  cout << weight+weight2;
}
