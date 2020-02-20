/*
ID:dx424391
PROG: rental
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

long long cows[100001];
pair<long long,long long> milk[100001];
long long sell[100001];
bool sorted(long long aa, long long bb){
  return aa>bb;
}
bool sorted2(pair<long long,long long> aa, pair<long long,long long> bb){
  return aa.second>bb.second;
}
long long re = 0,rep = 0;
long long resum = 0;
int main(){
  ofstream cout("rental.out");
  ifstream cin ("rental.in");
  long long a,b,c; cin >> a >> b >> c;
  for (long long i=0;i<a;i++) cin >> cows[i];
  for (long long i=0;i<b;i++) cin >> milk[i].first >> milk[i].second;
  for (long long i=0;i<c;i++) cin >> sell[i];

  sort(cows,cows+a,sorted);
  sort(milk,milk+b,sorted2);
  sort(sell,sell+c);
  long long pref = 0;
  for(long long i=0;i<min(a,c);i++)pref += sell[i];
  long long prefix = 0;
  long long ans = 0;
  long long price = 0;
  for (long long i=0;i<=a;i++){
    price = 0;
    if (i==0){
      price = pref;
    }else{
      prefix += cows[i-1];
      long long temp = prefix-resum;
      long long pos = re;
      price += rep;
      while(pos<b && temp!=0){
        if (temp>=milk[pos].first){
          temp-=milk[pos].first;
          price +=milk[pos].first*milk[pos].second;
          re++;
          resum+=milk[pos].first;
          rep+=milk[pos].first*milk[pos].second;
        }else{
          price += temp*milk[pos].second;
          temp = 0;

        }
        pos++;
      }
      if (i-a+c>0) pref -= sell[i-a+c-1];
      price+=pref;
      ans = max(ans,price);
    }
    //cout << price << endl;
  }
  cout << ans;
}
