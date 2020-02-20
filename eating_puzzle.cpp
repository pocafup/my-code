#include <iostream>
#include <vector>

using namespace std;

void solve(){
  vector<int> d;
  int maxi = 0;
  int a,b;
  int count = 0;
  cin >> a >> b;
  int c[b];
  for (int i = 0; i < b; i++){
    cin >> c[i];
    }
  for (int i=0; i<(1<<b);i++){
    int temp = 0;
    int sum = 0;

    for (int j=0; j<b;j++){
      int temp = i>>j;
      if (temp & 1){
          sum += c[j];
          count ++;

      }
      if (sum>maxi && sum<a){
        maxi = sum;
      }
    }
      d.clear();
    }

  cout << maxi;
}

int main(){
  solve();
}
