/*
ID:dx424391
PROG: fenceplan
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

pair<long long,long long> N[100000],M[100000];



int main(){
  ofstream cout("fenceplan.out");
  ifstream cin("fenceplan.in");
  long long a,b; cin >> a >> b;
  for (long long i=0;i<a;i++) cin >> N[i].first >> N[i].second;
  for (long long i=0;i<b;i++) {
    cin >> M[i].first >> M[i].second;
    if (M[i].first>M[i].second){
      long long temp = M[i].first;
      M[i].first = M[i].second;
      M[i].second = temp;
    }
  }
  sort(M,M+b);
  vector<long long> vec[100000];
  for (long long i=0;i<b;i++){
    vec[M[i].first-1].push_back(M[i].second-1);
    vec[M[i].second-1].push_back(M[i].first-1);
  }
  bool visited[a+1];
  memset(visited,0,sizeof(visited));
  long long pos = 0;
  pair<long long,long long> c = N[0];
  long long mini = 1000000000;
  // for (long long i=0;i<a;i++){
  //   for (long long j=0;j<vec[i].size();j++){
  //     cout << vec[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int n = 0;
  while(pos<a ){
    if (visited[pos] == false){
      visited[pos] = true;

      long long temp_max = 0;
      if (vec[pos].size()>0){
        queue<long long> q;
        for(long long i=0;i<vec[pos].size();i++){
          q.push(vec[pos][i]);
        }
        while(!q.empty()){
          if (visited[q.front()] == false){
            temp_max = max(temp_max,2*(abs(N[pos].first-N[q.front()].first)+abs(N[pos].second-N[q.front()].second)));

            visited[q.front()] = true;
            if (vec[q.front()].size()>0){
              for(long long i=0;i<vec[q.front()].size();i++){
                if (vec[q.front()][i]!=q.front()){
                  q.push(vec[q.front()][i]);
                }
              }
            }
          }

          q.pop();
        }
      }
      if (temp_max!=0) mini = min(temp_max,mini);
    }
    pos++;
  }
  cout << mini;
}
