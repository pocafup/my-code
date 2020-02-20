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
    float p2_x, float p2_y, float p3_x, float p3_y){
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
  bool out = false;

  ofstream cout("cowjump.out");
  ifstream cin("cowjump.in");
  int a; cin >> a;
  int b[a][4];
  for (int i=0;i<a;i++){
    for (int j=0;j<4;j++){
      cin >> b[i][j];
    }
  }
  int colli[a];
  memset(colli,0,sizeof(colli));
  bool nn = true;
  for (int i=0;i<a;i++){
    for (int j=i+1;j<a;j++){
      if (get_line_intersection(b[i][0],b[i][1],b[i][2],b[i][3],b[j][0],b[j][1],b[j][2],b[j][3])) {
        colli[i]++;
        colli[j]++;
        cout << i+1;
        break;
        // if (colli[i]>1){
        //   cout << i+1;
        //   out = true;
        //   nn = false;
        //   break;
        // }else if(colli[i]>1){
        //   cout << j+1;
        //   out = true;
        //   nn = false;
        //   break;
        // }

      }
    }
    if (!nn){
      break;
    }
  }
  // if (!out){
  //   for (int i=0;i<a;i++){
  //     if (colli[i]>1){
  //       cout << i+1;
  //       out = true;
  //       break;
  //     }
  //   }
  // }
  if (!out){
    for (int i=0;i<a;i++){
      if (colli[i]==1){
        cout << i+1;
        out = true;
        break;
      }
    }
  }
}
