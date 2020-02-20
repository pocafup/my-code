/*
ID:dx424391
PROG: perimeter
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;

char grid[1001][1001];
int visited[1001][1001];
int main(){
  // ofstream cout("perimeter.out");
  // ifstream cin ("perimeter.in");
  int temp1 = 0,temp2 = 0 ;
  int a; cin >> a;
  for (int i=0;i<a;i++)
    for (int j=0;j<a;j++)
      cin >> grid[i][j];
  queue<pair<int,int> > q;
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};

  int perimeter=0,area=0;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (grid[i][j]=='#' && !visited[i][j]){
        temp1 = 1,temp2 = 0;
        q.push(make_pair(i,j));
        visited[i][j] = true;
        while(!q.empty()){

          int x1 = q.front().first;
          int y1 = q.front().second;
          //cout << x1 << " " << y1 << " " << temp1 << " " << temp2 << endl;

          q.pop();
          for (int i=0;i<4;i++){
            if (x1+x[i]>=0 && x1+x[i]<a && y1+y[i]>=0 && y1+y[i]<a){
              if (!visited[x1+x[i]][y1+y[i]] && grid[x1+x[i]][y1+y[i]]=='#'){
                q.push(make_pair(x1+x[i],y1+y[i]));
                visited[x1+x[i]][y1+y[i]] = true;
                temp1++;
              }else if (grid[x1+x[i]][y1+y[i]]=='.'){
                temp2 ++;
              }
            }
            else temp2++;
          }
        }
        if (temp1>area || (temp1==area && temp2<perimeter)){
          area = temp1;
          perimeter = temp2;
        }
      }

    }
  }
  cout << area << " " << perimeter;
}
