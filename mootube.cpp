#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int> > connect[5001];
pair<int,int> ques[5001];
int dp[5001][5001];
queue<pair<int,int> > q;
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a-1;i++) {
    int c,d,e; cin >> c >> d >> e;
    c--;d--;
    connect[c].push_back(make_pair(d,e));
    connect[d].push_back(make_pair(c,e));
  }
  for (int i=0;i<b;i++) cin >> ques[i].first >> ques[i].second;
  for (int i=0;i<a;i++){
    //dp[i][i] = -1e8;
    q.push(make_pair(i,i));
    cout << endl << endl;
    while(!q.empty()){
      for (int k=0;k<a;k++){
        for (int j=0;j<a;j++){
          cout << dp[k][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
      int qf = q.front().first;
      int qs = q.front().second;
      q.pop();
      for (int j=0;j<connect[qf].size();j++){
        if (connect[qf][j].first!=qs){
          pair<int,int> cfq = connect[qf][j];
          if (dp[i][cfq.first]==0 && cfq.first!=i) {
            dp[i][cfq.first] = cfq.second;
            if (dp[i][qf]!=0) dp[i][cfq.first] = min(dp[i][cfq.first],dp[i][qf]);
            q.push(make_pair(cfq.first,i));
          }
          else{
            if (cfq.second!=dp[i][cfq.first]){

              dp[i][cfq.first] = min(dp[i][qf],min(dp[i][cfq.first],cfq.second));
              //q.push(make_pair(cfq.first,i));
            }
          }
        }

      }
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}
