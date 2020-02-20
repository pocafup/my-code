#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pp;
#define INF 2*1e8;
pp dp[1001][1001];
int n,p,k;
int a_i,b_i,l_i;
vector<pp> vec[1001];
int main(){
  cin >> n >> p >> k;
  for (int i=0;i<p;i++){
    cin >> a_i >> b_i >> l_i;
    if (a_i==1 && b_i == n) continue;
    a_i--;b_i--;

    vec[a_i].push_back(make_pair(b_i,l_i));
    vec[b_i].push_back(make_pair(a_i,l_i));
  }

  for (int i=0;i<=n;i++){
    for (int j=0;j<=n;j++){
      dp[i][j] = make_pair(2*1e8,2*1e8);
    }
  }
  for (int i=0;i<=n;i++) dp[0][i] = make_pair(0,0);
  queue<int> q;
  for (int i=0;i<vec[0].size();i++){
    q.push(vec[0][i].first);

    dp[vec[0][i].first][0] = make_pair(0,vec[0][i].second);
    for (int j=1;j<=k;j++) dp[vec[0][i].first][j] = make_pair(0,0);
  }
  cout << endl;
  while(!q.empty()){
    for (int i=0;i<n;i++){
      for (int j=0;j<=k;j++){
        cout << dp[i][j].second << " ";
      }
      cout << endl;
    }
    int qf = q.front();
    cout << "       " << qf+1 << endl;
    q.pop();
    for (int i=0;i<vec[qf].size();i++){
      int vt = vec[qf][i].first;
      int vs = vec[qf][i].second;
      bool nn =false;
      if (dp[vt][0].second>max(dp[qf][0].second,vs)){
        dp[vt][0] = make_pair(dp[qf][0].first,max(dp[qf][0].second,vs));
        nn = true;
      }
      for (int i=1;i<=k;i++){

        if (dp[vt][i].second>min(dp[qf][i-1].second,vs) ||
            dp[vt][i].second>max(dp[qf][i].second,vs)){
              if (dp[vt][i].second>min(dp[qf][i-1].second,vs)){
                dp[vt][i] = make_pair(dp[qf][i-1].first,min(dp[qf][i-1].second,vs));
              }
              if (dp[vt][i].second>max(dp[qf][i].second,vs)){
                dp[vt][i] = make_pair(dp[qf][i].second,min(dp[qf][i-1].second,vs));
              }
              nn = true;
            }
      }
      if (nn && vt!=n-1) q.push(vt);
    }
  }
  int mini = INF;
  cout << endl << endl;
  for (int i=0;i<n;i++){
    for (int j=0;j<=k;j++){
      cout << dp[i][j].second << " ";
    }
    cout << endl;
  }
  for (int i=0;i<=k;i++) mini = min(mini,dp[n-1][i].second);
  cout << mini;
}
