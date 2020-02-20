/*
ID:dx424391
PROG: mooyomooyo
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
  ifstream fin("mooyomooyo.in");
  ofstream fout("mooyomooyo.out");

  int a,b;
  fin >> a >> b;
  string c[a];
  queue<pair<int,int> > q;
  memset(c,0,sizeof(c));
  fin.ignore();
  for (int i=0;i<a;i++){
    getline(fin,c[i]);
  }
  string e[a];



  int varx[4] = {-1,0,0,1};
  int vary[4] = {0,1,-1,0};
  bool visited[a][10];
  memset(visited,0,sizeof(visited));
  bool n = true;
  queue<pair<int,int> > bb;
  while (n){
    n = false;
    for (int i=1;i<10;i++){
      memset(visited,0,sizeof(visited));

      for (int j=0;j<a;j++){
        for (int k=0;k<10;k++){
          if (visited[j][k] == false){
            if (int(c[j][k]-48) != i){
              visited[j][k] = true;
            }else{
              pair<int,int> s;
              s.first = j;
              s.second = k;
              q.push(s);
              bb.push(s);
              visited[j][k] = true;
              int count = 1;
              while (!q.empty()){
                for (int aa = 0;aa<4;aa++){
                  if (q.front().first+varx[aa]>=0 && q.front().first+varx[aa]<a && q.front().second+vary[aa]>=0 && q.front().second+vary[aa]<10){
                    if (visited[q.front().first+varx[aa]][q.front().second+vary[aa]]== false && int(c[q.front().first+varx[aa]][q.front().second+vary[aa]]-48) == i){
                      visited[q.front().first+varx[aa]][q.front().second+vary[aa]] = true;
                      pair<int,int> s2;
                      s2.first = q.front().first+varx[aa];
                      s2.second = q.front().second+vary[aa];
                      q.push(s2);
                      count++;
                      bb.push(s2);
                    }
                  }
                }
                q.pop();
              }
              if (count>=b){
                while(!bb.empty()){
                  c[bb.front().first][bb.front().second] = 48;
                  bb.pop();
                }
              }else{
                while(!bb.empty()){
                  bb.pop();
                }
              }
            }
          }
        }
      }
    }
    for (int i=0;i<a;i++){
      for (int j=0;j<10;j++){
        e[i][j] = c[i][j];
      }
    }

    for (int i=0;i<10;i++){
      int pos = a-1;
      for (int j=a-1;j>=0;j--){
        if (c[j][i] != 48){
          c[pos][i] = c[j][i];
          c[j][i] = 48;
          if (pos!=j){
            n=true;
          }
          pos--;

        }
      }
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<10;j++){
      fout << e[i][j];
    }
    fout << endl;
  }
  return 0;
}
