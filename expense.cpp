#include <iostream>
#include <algorithm>

using namespace std;

int buc[100001];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++){
    cin >> buc[i];
  }
  int right = 1e6+5;
  int left = 0;

  while(left != right-1){
    //cout << left << " " << right;
    int mid = (right-left)/2+left;
    int st = 1,temp = 0;
    bool n = true;
    for(int i=0;i<a;i++){
      if (buc[i]>mid){
        left = mid;
        n = false;
        break;
      }else{
        if (temp+buc[i]<=mid){
          temp += buc[i];
        }else{
          temp = 0; 
          st++;
          if (st>b){
            left = mid;
            n = false;
            break;
          }
        }
      }
    }
    if (n) right = mid;
  }
  cout << right;
}
