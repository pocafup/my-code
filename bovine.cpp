#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector<int> n[100000];
bool visited[100000];
int main(){
  int a,b; cin >> a >> b;
  queue<int> q;
  for (int i=0;i<b;i++){
    int c,d; cin >> c >> d;
    n[c].push_back(d);
    n[d].push_back(c);
  }
  int begin = 0;
  vector<int> vec[10000];
  for (int i=0;i<a;i++){
    if (!visited[i]){
      visited[i] = true;
      for (int j=0;j<n[i].size();j++){
        q.push(n[i][j]);
        vec[begin].push_back(n[i][j]);
      }
      while(!q.empty()){
        visited[q.front()] = true;
        for (int k=0;k<n[q.front()].size();k++){
          if(!visited[n[q.front()][k]]){
            q.push(n[q.front()][k]);
            vec[begin].push_back(n[q.front()][k]);
          }

        }
        q.pop();
      }
      begin++;
    }
  }
  for (int i=0;i<begin;i++){
    for (int j=0;j<vec[i].size();j++){
      cout << vec[i][j] << " ";
    }
    cout << endl;
  }
}
