#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int road[100001],left_bound,right_bound;
int main(){
  // ifstream cin ("haybales.in");
  // ofstream cout ("haybales.out");
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> road[i];
  sort(road,road+a);
  for (int i=0;i<b;i++){
    int c,d; cin >> c >> d;
    int left = 0,right = a-1;
    while(left!=right-1){
      int mid = (left+right)/2;
      if (road[mid]>c){
        right = mid;
      }else{
        left = mid;
      }
    }
    if (road[right]>c){
      left_bound = left;
    }else{
      left_bound = right;
    }
    left = 0,right = a-1;
    while(left!=right-1){
      int mid = (left+right)/2;
      if (road[mid]>d){
        right = mid;
      }else{
        left = mid;
      }
    }
    if (road[right]>d){
      right_bound = left;
    }else{
      right_bound = right;
    }
    // cout << left << " " << right << endl;
    int touch = 0;
    if (road[left_bound]>=c) touch = 1;
    // cout << left_bound  << " " << right_bound << "    ";
    cout << right_bound-left_bound+touch << endl;
  }
}
