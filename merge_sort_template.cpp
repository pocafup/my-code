#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int n;
vector<int> vec;
vector<int> merge(int ft, int bk, vector<int> tmp){
  vector<int> tmp1,tmp2, new_tmp;
  if (ft==bk) return tmp;
  int mid = (ft+bk)/2;
  for (int i=ft;i<mid;i++) tmp1.push_back(tmp[i]);
  for (int i=mid+1;i<bk;i++) tmp2.push_back(tmp[i]);
  tmp1 = merge(0,tmp1.size(),tmp1);
  tmp2 = merge(0,tmp2.size(),tmp2);
  while(tmp1.size()||tmp2.size()){
    if (tmp1.size() && tmp2.size()){
      if (tmp1[tmp1.size()-1]>tmp2[tmp2.size()-1]){
        new_tmp.push_back(tmp2[tmp2.size()-1]);
        tmp2.pop_back();
      }else{
        new_tmp.push_back(tmp1[tmp1.size()-1]);
        tmp1.pop_back();
      }
    }else if (tmp1.size()) {new_tmp.push_back(tmp1[tmp1.size()-1]);tmp1.pop_back();
    }else if (tmp2.size()) {new_tmp.push_back(tmp2[tmp2.size()-1]);tmp2.pop_back();}

  }
  return tmp;
}
int main(){
  cin >> n;
  for (int i=0;i<n;i++) {int a; cin >> a; vec.push_back(a);}
  vec = merge(0,n-1,vec);
}
