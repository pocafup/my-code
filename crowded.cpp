#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

pair<int,int> cows[100001];
int main(){
  int a,b; cin >> a >>b;
  for (int i=0;i<a;i++) cin >> cows[i].first >> cows[i].second;
  sort(cows,cows+a);
  int c = 1;
  int curr = 0;
  int ans = 0;
  int begin = 0;

  set<pair<int,int> > left,right;
  while(curr!=c-1 || (c!=a)){

    while(cows[curr].first-cows[begin].first>b){
      left.push(make_pair(begin,cows[begin].second));
      begin++;
    }
    while (cows[c].first-cows[curr].first<=b) {
      if (c==a) break;
      right.push(make_pair(c,cows[c].second));
      c++;
    }
    if ()
    //cout << begin << " " << c << endl;
    // for (int i=curr+1;i<c;i++){
    //   bool n = true;
    //   for (int k=begin;k<curr;k++){
    //
    //     if (cows[curr].second*2<= cows[k].second &&cows[i].second>=cows[curr].second*2) {
    //         ans +=1;
    //         n = false;
    //         break;
    //
    //     }
    //
    //   }
    //   if (!n) break;
    // }
    curr ++;
    if (curr == c && c!=a) c++;
  }
  cout << ans;
}
