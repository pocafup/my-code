#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main(){
  int a; cin >> a;
  vector<pair<int,pair<int,int> > > b;
  for (int i=0;i<a;i++){
    int t1,t2;
    cin >> t1 >> t2;
    b.push_back(make_pair(i,make_pair(t1,t2)));
  }
  int n = 0;
  long long mini = 0;
  int re;
  while (b.size()>1){
    mini = 10000000000;
    for(int i=0;i<b.size();i++){

      if (i!=n && pow(b[i].second.first-b[n].second.first,2)+pow(b[i].second.second-b[n].second.second,2)<mini){
        mini = pow(b[i].second.first-b[n].second.first,2)+pow(b[i].second.second-b[n].second.second,2);
        re = i;
      }
    }
  //  cout << re << endl;
    if (re>n){
      b.erase(b.begin()+re);
      n++;
    }else{
      b.erase(b.begin()+re);
    }
    if (n>=b.size()){
      n = 0;
    }

  }
  cout << b[0].first+1;
}
