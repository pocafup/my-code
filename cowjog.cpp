#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a;
  cin >> a;
  pair<int,int> b[a];
  int plot = 1;
  for (int i=0;i<a;i++){
    cin >> b[i].first >> b[i].second;
  }
  int min = b[a-1].second;
  for (int i=a-2;i>=0;i--){
    if (b[i].second <= min){
      min = b[i].second;
      plot++;
    }
  }
  cout << plot;
}
