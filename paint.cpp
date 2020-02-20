#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
  int a,b,c,d;
  int visited[10000];
  memset(visited,0,sizeof(visited));
  queue<pair<int,int> > que;
  cin >> a >> b >> c >> d;
  int e[c];
  for (int i=0;i<c;i++){
    cin >> e[i];
  }
  pair<int,int> f;
  f.first = a;
  f.second = 0;
  que.push(f);
  while(!que.empty() ){
    bool s = true;
    cout << que.size() << endl;
    if (que.size()<5){
      cout << que.front().first << " " << que.front().second << endl;

    }
    for (int i=0;i<c;i++){
      pair<int,int> g;
      g.first = que.front().first*e[i]%d;
      g.second = que.front().second +1;
      if (visited[g.first] == false){
        visited[g.first] = true;
        que.push(g);
      }
      if (g.first == b){
        cout << g.second;
        s = false;
        break;
      }
    }
    que.pop();
    if (!s){
      break;
    }
  }


}
