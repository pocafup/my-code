#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  string a,b;
  getline(cin,a);
  getline(cin,b);
  int maxi = 0;
  int temp = 0;
  for (int i=0;i<a.size();i++){
    for (int j=0;j<b.size();j++){
      if (a[i] == b[j]){
        temp = 1;
        bool d = true;
        int n1 = i+1,n2 = j+1;

        while(d && n1<a.size() && n2<b.size()){
          d = false;
          if(a[n1] == b[n2]){
            temp ++;
            d = true;
          }
          n1++;
          n2++;
        }
        maxi = max(maxi,temp);
      }
    }
  }
  cout << maxi;

}
