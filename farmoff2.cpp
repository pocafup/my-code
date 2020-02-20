#include <iostream>
#include <algorithm>

using namespace std;

long long expt(long long aa, long long bb, long long cc){
  long long re = 1;
  for (long long i=0;i<bb;i++){
    re = (re*aa)%cc;
  }
  return re;
}
int main(){
  long long int n,a,b,c,d,e,f,g,h,m;
  cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m;
  long long int utility,utility2 = 0;
  long long int weight,weight2 = 10000000000;
  for (long long int i=0;i<3*n;i++){
    long long int W_i,U_i;
    W_i = ((a*expt(i,5,d))%d+(b*expt(i,2,d))%d+c%d)%d;
    U_i = ((e*expt(i,5,h))%h+(f*expt(i,3,h))%h+g%h)%h;
    cout << U_i << " " << W_i << endl;

    if (U_i>utility){
      utility2 = utility;
      weight2 = weight;
      utility = U_i;
      weight = W_i;
      cout << utility << " " << weight <<" "<< i <<endl;

    }else if(U_i == utility){
      if (U_i != utility2){
        utility2 = U_i;
        weight2 = W_i;
        cout << utility2 << " " << weight2 <<" "<< i <<endl;

      }else{
        if (W_i<weight2){
          utility2 = U_i;
          weight2 = W_i;
          cout << utility2 << " " << weight2 <<" "<< i <<endl;

        }
      }
    }else if (U_i>utility2){
        utility2 = U_i;
        weight2 = W_i;
        cout << utility2 << " " << weight2 <<" "<<i <<endl;

    }else if (U_i == utility2){
      if (W_i<weight2){
        utility2 = U_i;
        weight2 = W_i;
        cout << utility2 << " " << weight2 <<" "<< i <<endl;

      }

    }
  }
  cout<< weight << " " << weight2 << endl;

  cout << (weight+weight2)%m;
}
