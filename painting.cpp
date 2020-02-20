#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int l[100000];
bool check[100000];
pair<int,int> s_e_point[100000];
int weird[100000];
int main(){
  int a; cin >> a;
  int paint_num = 1;
  int total = 0;
  for (int i=0;i<a;i++) cin >> l[i];
  for (int i=0;i<a;i++) {if (l[i] == 0) check[i] = true;}
  for (int i=0;i<a;i++) weird[l[i]]++;
  for (int i=0;i<a;i++) if (weird[i]!= 0) total++;
  for (int i=0;i<a;i++){
    if (s_e_point[l[i]].first==0) s_e_point[l[i]].first = i;
    if (s_e_point[l[i]].second<i) s_e_point[l[i]].second = i;
  }
  int count = 0;

  while(paint_num<total){
    int front = 0;
    while(front<a){
      while(check[front] == true) front++;
      if (front == a) break;
      for (int i=front;i<=s_e_point[l[front]].second;i++){
        if (l[i] == l[front]) check[i] = true;
      }
      paint_num++;

      front = s_e_point[l[front]].second+1;
    }
    count ++;

  }
  cout << count;
}
