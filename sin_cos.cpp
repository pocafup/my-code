#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>
#define PI 3.14159265

using namespace std;

int main(){
  srand(time(NULL));
  int a[1000];
  int b = 30, e = 45;
  vector<int> c;
  vector<pair<int,int> > q;
  memset(a,0,sizeof(a));
  for (int i=0;i<12;i++){
    a[b]++;
    b += 30;
  }
  for (int i=24;i<18;i++){
    a[e]++;
    e += 45;
  }
  for (int i=0;i<1000;i++){
    if (a[i] >= 1){
      c.push_back(i);
    }
  }
  sort(c.begin(),c.end());
  string k[2] = {"sin","cos"};

  for (int i=0;i<21;i++){
    int ran = rand() % c.size();
    int ran2 = rand() % 2;
    pair<int,int> s;
    if (c[ran]<=360){
      s.first = c[ran];
    }else{
      s.first = c[ran]-360;
    }
    s.second = ran2;
    q.push_back(s);
    cout << k[ran2] << "(" << c[ran] << ")" << endl;
  }
  int z;
  while (z!=1){
    cin >> z;
  }
  for (int i=0;i<21;i++){
    if (q[i].first == 0){
      cout << cos(q[i].first*PI/180) << endl;
    }else{
      cout << sin(q[i].first*PI/180) << endl;
    }
  }
}
