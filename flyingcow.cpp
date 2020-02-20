#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(){
  int a;
  cin >> a;
  int c = 1;
  bool b[1000000];
  memset(b,0,sizeof(b));
  queue<pair<int,int> > q;
  pair<int,int> e;
  e.first = 1;
  e.second = 0;
  q.push(e);

  while (q.size() && q.front().first != a ){
    pair<int,int> d;
    d.first = q.front().first*3;
    d.second = q.front().second+1;
    if (d.first<1000000){
      if (b[d.first] == false){
          b[d.first] = true;
          q.push(d);
      }
    }
    if (d.first<1000000){
      if (d.first == a){
        cout << d.second;
        break;
      }
    }
    d.first = q.front().first+1;
    if (d.first<1000000){
      if (b[d.first] == false){
          b[d.first] = true;
          q.push(d);
      }
    }
    if (d.first == a){
      cout << d.second;
      break;
    }
    if (q.front().first-1>=0){
        d.first = q.front().first-1;
          q.push(d);

        if (d.first<1000000){
          if (d.first == a){
            cout << d.second;
            break;
          }
        }
    }
    q.pop();

  }
  if(q.front().first == a){
    cout << q.front().second;
  }
}
