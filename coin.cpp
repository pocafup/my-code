#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

long long comb[1000];

int main(){
  long long a,b; cin >> a >> b;

  for (long long i=0;i<a;i++){
    cin >> comb[i];
  }
  sort(comb,comb+a);
  vector<long long> dp;
  long long n = 1;
  long long re = comb[0];
  long long res = 0;
  for (long long i=1;i<a;i++){
    if (comb[i]-re>5){
      if (dp.size()==b){
        if (n>dp[0]){
          dp[0] = n;
          while(comb[i]-re>5){
            n--;
            res++;
            re = comb[res];
          }
          n++;
          re = comb[res];
          sort(dp.begin(),dp.end());
        }
      }else{
        dp.push_back(n);
        while(comb[i]-re>5){
          n--;
          res++;
          re = comb[res];
        }
        n++;
        //re = comb[res];
        sort(dp.begin(),dp.end());
      }
    }else{
      n++;
    }
  }
  if (dp.size()==b){
    if (n>dp[0]){
      dp[0] = n;
      n = 1;
      sort(dp.begin(),dp.end());
    }
  }else if(dp.size()<b){
    dp.push_back(n);
  }
  long long count = 0;
  for (long long i=0;i<dp.size();i++){
    count += dp[i];
  }
  cout << count;
}
