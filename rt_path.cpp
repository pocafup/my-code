#include <iostream>
#include <string>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  char c[1000][1000];
  char cc[4] = {'d','r','l','u'};
  int x[4] = {0,1,-1,0};
  int y[4] = {1,0,0,-1};
  //cout << "aa";
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> c[j][i];
    }
  }
  //cout << "aa";
  string d; cin >> d;
  int posx = 1, posy = 1;
  bool rt = true;
  int n = 0;
  //cout << d.size();
  while (rt && n<d.size()){
    //cout <<n  << endl;
    for (int i=0;i<4;i++){
      if (d[n] == cc[i]){
        posx += x[i];
        posy += y[i];
      }
    }
    if (posx>=a or posy >= b or posx<0 or posy<0){
      rt = false;
    //  cout << "bb";
    }else if(c[posx][posy] == '#'){
      cout << "zz";
      rt = false;
    }
    n++;
  }
  if (rt && posx==b-1){
    cout << "Right path!";
  }else{
    cout << "Wrong path!";
  }
}
