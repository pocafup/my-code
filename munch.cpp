#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int main(){
  int b,c;
  cin >> b >> c;
  int a[b][c];
  bool visited[b][c];
  int checkx[4] = {-1,0,0,1};
  int checky[4] = {0,-1,1,0};
  queue<pair <pair<int,int>,int> > q;
  memset(a,0,sizeof(a));
  memset(visited,0,sizeof(visited));
  for (int i=0;i<b;i++){
    for (int j=0;j<c;j++){
      char d;
      cin >> d;
      if (d == 'B' or d == '.'){
        a[i][j] = 0;
      }else if (d == '*'){
        a[i][j] = 1;
        visited[i][j] = true;
      }else if (d == 'C'){
        a[i][j] = 2;
      }
    }
  }
  pair<pair<int,int>,int> s;
  s.first.first = 0;
  s.first.second = 0;
  s.second = 0;
  q.push(s);
  visited[0][0] = true;
  bool bo = true;
  while(!q.empty() && bo == true){
  //  cout << "aa" << endl;
    for (int i=0;i<4;i++){
    //  cout << q.front().first.first+checkx[i] << " " << q.front().first.second+checky[i] << endl;
      if (q.front().first.first+checkx[i]>=0 && q.front().first.second+checky[i]>=0 && q.front().first.first+checkx[i]<b && q.front().first.second+checky[i]<c){
      //  cout << visited[q.front().first.first+checkx[i]][q.front().first.second+checky[i]] << "visited" << endl;
        if (visited[q.front().first.first+checkx[i]][q.front().first.second+checky[i]] == false){
          visited[q.front().first.first+checkx[i]][q.front().first.second+checky[i]] = true;
          pair<pair<int,int>,int> s2;
          s2.first.first = q.front().first.first+checkx[i];
          s2.first.second = q.front().first.second+checky[i];
        //  cout << s2.first.first << " " << s2.first.second << endl;
          //cout << a[s2.first.first][s2.first.second] << endl;
          s2.second = q.front().second+1;
          q.push(s2);
          if (a[s2.first.first][s2.first.second] == 2){
            cout << s2.second ;
            bo = false;
          }

        }
      }
    }
    q.pop();
    //cout << bo <<endl;
  }

}
