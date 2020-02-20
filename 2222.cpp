#include<iostream>
#include<string>
#include<queue>
using namespace std;

bool visited[10000];

int main(){
  int a,b,c,d,e;
  cin >> a >> b;
  cin >> c >> d;
  int m[c];
  queue<int> q;
  queue<int> dis;

  dis.push(0);
  int times = 0;
  for (int i = 0; i < c; i++){
    cin >> m[i];
  }
  q.push(a);
  while(!q.empty()){
    int aa = q.front();
    //cout << aa << " aa ";
    int dist = dis.front();
    if (aa==b){
      cout << dis.front();
      break;
    }

    for (int i=0;i<c;i++){
      if (visited[(m[i]*aa) % d]==false){
        visited[i]=true;
        e = ((m[i]*aa) % d);
        q.push(e);
        dis.push(dist+1);
      }
    q.pop();
    dis.pop();
    }

  }



}
