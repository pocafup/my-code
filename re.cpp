#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int num;
int main(){
  int a,b;
  cin >> a >> b;
  string c;
  int d[a];

  for (int i=0;i<a;i++){
    d[i] = 0;
  }
  for (int i=0;i<b;i++){
    int e,f;
    cin >> e >> f;
    for(int j=e-1;j<f;j++){
      d[j] = int(d[j])+1;
    }
  }
  sort(d,d+a);
  cout << d[0] << endl;
  if (a%2!= 0){
    num = (a-1)/2;
  }else{
    num = (a/2)-1;
  }
  cout << d[num];
}
