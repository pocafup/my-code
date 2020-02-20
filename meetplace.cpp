#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
int pa[1001];
int ans[1001][1001];
pair<int,int> pos[1001];
int level[1001];
queue<pair<int,int> > q;
int visited[1001];
int start[1001];
vector<int> vec[1001];
int c,d;
int lca(int a,int b){
  if (a==b) return a;
  int start1 = start[a]-1,start2 = start[b]-1;
  if (start1>start2){swap(a,b);swap(start2,start1);}
  while(ans[a][start1]==ans[b][start2] && ans[a][start1]!=-1) {
    start1--;start2--;
    if (start1<0 || start2<0) break;
  }

  if (ans[b][start2]==a) return a;
  return ans[a][start1+1];
}

int main(){

  int a,b; cin >> a >> b;
  for (int i=1;i<a;i++) {cin >> pa[i];pa[i]--;vec[pa[i]].push_back(i);}
  for (int i=1;i<=a;i++){
    for (int j=0;j<a;j++){
      ans[i][j] = -1;
    }
  }
  for (int i=0;i<b;i++){
    cin >> pos[i].first >> pos[i].second;
    pos[i].first--; pos[i].second--;
  }
  for (int i=0;i<=a;i++){
    for (int j=0;j<a;j++){
      ans[i][j] = -1;
    }
  }

  for (int i=1;i<=a;i++) ans[i][0] = pa[i];
  for(int i = 1 ; i <= a ; i++){
    for(int j = 1; j < a ; j++){
      if(ans[i][j-1] != -1) ans[i][j] = ans[ans[i][j-1]][0] ;
      else {start[i] = j-1;break;}
    }
  }
  // for (int i=0;i<=a;i++){
  //   cout << i << "   ";
  //   for (int j=0;j<a;j++){
  //     cout << ans[i][j]+1 << " ";
  //   }
  //   cout << "   ee" <<  endl;
  // }
  // cout << endl;
  // q.push(make_pair(0,1));
  // visited[0] = true;
  // while(!q.empty()){
  //   int qf = q.front().first;
  //   int qs = q.front().second;
  //   level[qf] = qs;
  //   q.pop();
  //   for (int i=0;i<vec[qf].size();i++){
  //     if (!visited[vec[qf][i]]) q.push(make_pair(vec[qf][i],qs+1));
  //   }
  // }
  for (int i=0;i<b;i++){
    cout << lca(pos[i].first,pos[i].second)+1 << endl;
  }
}
