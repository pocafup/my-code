/*
ID:dx424391
PROG: perimeter
LANG:C++
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int visited[1000][1000];
char b[1000][1000];
int a;
int getside(pair<int,int> point){

  int side = 0;
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  for (int i=0;i<4;i++){
    if (x[i]+point.first<a && x[i]+point.first>=0 && y[i]+point.second<a && y[i]+point.second>=0){
      if (b[x[i]+point.first][y[i]+point.second] == '.'){
        side ++;
      }
    }else{
      side++;
    }
  }
  return side;
}
int main(){
  ofstream fout("perimeter.out");
  ifstream fin("perimeter.in");
  fin >> a;
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  for (int i=0;i<a;i++){for (int j=0;j<a;j++){fin >> b[i][j];} }
  //for (int i=0;i<a;i++){for (int j=0;j<a;j++){fout << b[i][j] ;}fout << endl;}
  int pt = 0;
  queue<pair<int,int> > q;
  vector<pair<int,int> > plot[2];
  memset(visited,0,sizeof(visited));
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      if (b[i][j] != '.' && visited[i][j] == false){
        visited[i][j] = true;
        q.push(make_pair(i,j));
        plot[pt].push_back(make_pair(i,j));
      }
      while(!q.empty()){
        for (int k=0;k<4;k++){
          if (x[k]+q.front().first<a && x[k]+q.front().first>=0 && y[k]+q.front().second<a && y[k]+q.front().second>=0){
            if (visited[x[k]+q.front().first][y[k]+q.front().second]==0 && b[x[k]+q.front().first][y[k]+q.front().second]=='#'){
              //fout << x[k]+q.front().first <<" " <<  y[k]+q.front().second << endl;
              visited[x[k]+q.front().first][y[k]+q.front().second] = 1;
              q.push(make_pair(x[k]+q.front().first,y[k]+q.front().second));
              plot[pt].push_back(make_pair(x[k]+q.front().first,y[k]+q.front().second));
            }
          }
        }
        q.pop();
        if (q.empty()){
          pt++;
        }
      }
    }
  }
  int re[pt];
  for (int i=0;i<pt;i++){re[i] = plot[i].size();}
  int temp[pt];
  // fout << pt << endl;
  // fout << plot[0].size() << endl;
  // fout << plot[1][0].first << " " << plot[1][0].second << endl;
  for (int i=0;i<2;i++){
    temp[i] = 0;
    while (!plot[i].empty()){
      temp[i] += getside(plot[i][0]);
      //fout << plot[i][0].first << " " << plot[i][0].second << " " << getside(plot[i][0]) << endl;
      plot[i].erase(plot[i].begin());
    }
  }
  if(re[0] > re[1]){
    fout << re[0] << " "<< temp[0];
  }else if (re[0]<re[1]){
    fout << re[1] << " "<< temp[1];
  }else{
    if(temp[0]  < temp[1]){
      fout << re[0] <<" "<< temp[0];
    }else{
      fout << re[1] << " "<< temp[1];
    }
  }
}
