/*
ID:dx424391
PROG: perimeter
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
  ofstream fout("perimeter.out");
  ifstream fin("perimeter.in");
  int a;
  cin >> a ;
  bool visited[a+2][a+2];
  char e[a+2][a+2];
  int  b[a+2][a+2];
  memset(visited,0,sizeof(visited));
  memset(b,0,sizeof(b));
  memset(e,0,sizeof(e));
  queue<pair<int,int> > q;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      cin >> e[i][j];
      if (e[i][j] == '#'){
        b[i][j] = 1;
      }else{
        b[i][j] = 0;
      }
    }
  }

  int plot = 1;
  int varx[4] = {-1,0,1,0};
  int vary[4] = {0,-1,0,1};
  int maxi = 0;
  int temp = 0;
  int maxi2 = 0;
  int ploto = 0;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (b[i][j] == 1 && visited[i][j] == false){
        b[i][j] = plot;
        visited[i][j] = true;
        pair<int,int> start;
        start.first = i;
        start.second = j;
        q.push(start);
        temp = 1;
        while(!q.empty()){
          visited[q.front().first][q.front().second] = true;
          for(int k=0;k<4;k++){
            if (varx[k]+q.front().first >= 0 && varx[k]+q.front().first < a && vary[k]+q.front().second >= 0 && vary[k]+q.front().second < a){
              if (b[varx[k]+q.front().first][vary[k]+q.front().second] == 1 && visited[varx[k]+q.front().first][vary[k]+q.front().second] == false){
                b[varx[k]+q.front().first][vary[k]+q.front().second] = plot;
                pair<int,int> s;
                s.first = varx[k]+q.front().first;
                s.second = vary[k]+q.front().second;
                q.push(s);
                temp ++;
              }
            }
          }
          q.pop();
        }

        plot++;
      }
      if (temp>maxi){
        maxi = temp;
        ploto ++;
        temp = 1;
      }
    }
  }
  queue<pair<int,int> > q2;
  int count = 0;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (b[i][j] == ploto){
        pair<int,int> s2;
        s2.first = i;
        s2.second = j;
        q2.push(s2);
        count ++;
      }
    }
  }
  int perimeter = 0;
  while(!q2.empty()){
    for(int k=0;k<4;k++){
      if (varx[k]+q2.front().first >= 0 && varx[k]+q2.front().first < a && vary[k]+q2.front().second >= 0 && vary[k]+q2.front().second < a){
        if (b[varx[k]+q2.front().first][vary[k]+q2.front().second] == 0){
          perimeter++;
        }
      }else if(varx[k]+q2.front().first < 0 or varx[k]+q2.front().first >= a or vary[k]+q2.front().second < 0 or vary[k]+q2.front().second >= a){
        perimeter++;
      }
    }
    q2.pop();
  }
  cout << maxi << " "<<perimeter << endl;


}
