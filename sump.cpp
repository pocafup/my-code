#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool sorted(pair<pair<long long,long long>,long long> fi, pair<pair<long long,long long>,long long> se){
    if (fi.first.second == se.first.second){
        return fi.first.first < se.first.first;
    }else{
          return fi.first.second<se.first.second;

    }
}
int main(){
  long long a,b,c; cin >> a >> b >> c;
  pair<pair<long long,long long>,long long> inv[b];
  for (long long i=0;i<b;i++){
    cin >> inv[i].first.first >> inv[i].first.second >> inv[i].second;
  }
  sort(inv,inv+b,sorted);
  cout << endl;
  for (long long i=0;i<b;i++){
    cout << inv[i].first.first << " " << inv[i].first.second << " " << inv[i].second << endl;
  }
  cout << endl;
  pair<long long,int> dp[b+3];
  memset(dp,0,sizeof(dp));
  dp[0] = make_pair(inv[0].second,inv[0].first.second);
  int pos = 1;
  for (int j=1;j<b;j++){
    int n = pos-1;
    bool e = true;
    dp[pos] = dp[pos-1];
    while (n>=0 && e){
      if (inv[j].first.first-2>dp[n].second){
        if (dp[pos].first<dp[n].first+inv[j].second){
          dp[pos] = make_pair(dp[n].first+inv[j].second,inv[j].first.second);
          e = false;
        }
      } 
      n--;
    }
    if (inv[j].second > dp[pos].first){
      dp[pos] = make_pair(inv[j].second,inv[j].first.second);
    }
    pos++;

  }
  for (int i=0;i<b;i++){
    cout << dp[i].first << " ";
  }
  cout << dp[b-1].first;
}
