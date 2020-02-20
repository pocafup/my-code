/*
ID:dx424391
PROG: cowjump
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

char get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y,
    float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y){
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;
    s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;
    s2_y = p3_y - p2_y;
    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);
    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {

        return 1;
    }
    return 0;
}

int main(){
  ofstream fout("cowjump.out");
  ifstream fin("cowjump.in");
  int a; fin >> a;
  int point[a][4];
  for (int i=0;i<a;i++){
    fin >> point[i][0] >> point[i][1] >> point[i][2] >> point[i][3];
  }
  int colli[a];
  memset(colli,0,sizeof(colli));
  for (int i=0;i<a;i++){
    for (int j=i+1;j<a;j++){

      if (get_line_intersection(point[i][0],point[i][1],point[i][2],point[i][3],point[j][0],point[j][1],point[j][2],point[j][3],k,l)){
        colli[i]++;
        colli[j]++;
      }
    }
  }
  for (int i=0;i<a;i++){
    if (colli[i]>1){
      fout << colli[i];
    }
  }
}
