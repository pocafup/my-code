#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int prefix[100001];
int dp[100001];
int cowin[100001];
vector<int> pos;
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++){
    int b; cin >> b;
    pos.push_back(b);
  }
  cout << pos.size();
  cout << pos[a-1];
  prefix[0] = pos[0]-1;
  int renum = 0;
  int repos = 0;
  int ans = 0;
  for (int i=1;i<a;i++) {
    prefix[i] = prefix[i-1]-1+pos[i];
    if (prefix[i]<renum){renum = prefix[i];repos = i;}
  }
  (repos+1 == a) ? repos = repos+1-a : repos = repos+1;
  for (int i=0;i<a;i++) cout << prefix[i] << endl;
  cout << repos << " " << renum << endl;
  dp[repos] = 0;
  cowin[repos] = pos[repos];
  int bot = 0;
  for (int i=0;i<a;i++){
    //cout << bot << endl;
    if (repos+i+1<a){
      dp[repos+i+1] += cowin[repos+i]-1;
      cowin[repos+i+1] += pos[repos+i+1]+cowin[repos+i]-1;
      bot = dp[repos+1+i];
      for (int j=bot-dp[repos+1+i]+1;j<=bot;j++){
        ans += j*j;
      }
    }else if (repos+i+1==a){
      dp[repos+1+i-a] += cowin[repos+i]-1;
      cowin[repos+i+1-a] += pos[repos+i+1-a]+cowin[repos+i]-1;
      bot = dp[repos+i+1-a];
      for (int j=bot-dp[repos+1-a+i]+1;j<=bot;j++){
        ans += j*j;
      }
    }else{
      dp[repos+i+1-a] += cowin[repos+i-a]-1;
      cowin[repos+i+1-a] += pos[repos+i+1-a]+cowin[repos+i-a]-1;
      bot = dp[repos+i+1-a];
      for (int j=bot-dp[repos+i+1-a]+1;j<=bot;j++){
        ans += j*j;
      }
    }
    for (int j=0;j<a;j++) cout << dp[j] << " ";
    cout << endl;
  }
  cout << ans;
}
