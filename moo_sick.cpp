#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a,b;
int n = 0;
bool big;
bool True = true;
vector<int> c,res;
int main(){
  cin >> a;
  for (int i=0;i<a;i++){
    int cc;
    cin >> cc;
    c.push_back(cc);
  }
  cin >> b;
  int d[b];
  for (int i=0;i<b;i++){
    cin >> d[i];
  }
  sort(d,d+b);
  for(int i=0;i<c.size()-b+1;i++){
    int re[b];
    for (int j=0;j<b;j++){
      re[j] = c[j+n];
    }
    sort(re,re+b);
    int less = abs(re[0]-d[0]);
    if (re[0]>d[0]){
      big = true;
    }else{
      big = false;
    }
    for(int j=0;j<b;j++){
      if(big){
        if(re[j]-d[j]!=less){
          True = false;
        }
      }else{
        if(d[j]-re[j]!=less){
          True = false;
        }
      }

    }
    if (True){
      res.push_back(n+1);
    }else{
      True = true;
    }
    n++;
  }
  cout << res.size() << endl;
  for (int i=0;i<res.size();i++){
    cout << res[i] << endl;
  }
}
