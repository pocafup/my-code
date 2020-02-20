#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

bool sec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main(){
  int a,b,c,maxi;
  maxi = 0;
  cin >> a >> b >> c;
  pair<char,int> d[a];
  for (int i=0;i<a;i++){
    cin >> d[i].first;
    cin.ignore();
    cin >> d[i].second;
  }
  sort(d,d+a,sec);
  for (int i=0;i<a;i++){
    cout << d[i].first << " " << d[i].second << endl;
  }
  int pos = 0;
  bool start = false;
  int res,res2 = 0;


  while (pos<a){

    if (d[pos].first == 'S' && start == false){
      if (pos != 0){
        maxi += (d[pos].second-res2)/2+1;
      }
      start = true;
      res = d[pos].second;
    }
    if (d[pos].first == 'N' && start == true){
      start = false;
      maxi += (d[pos].second-res)/2+1;
    }
    if (d[pos].first == 'N'){
      res2 = d[pos].second;
    }
    pos++;
  }
  cout << maxi;
}
