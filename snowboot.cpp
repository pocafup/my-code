#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int arr[80000];
int main(){
  int a; cin >> a;
  vector<int> vec[80000];
  cout << endl << endl;
  for (int i=0;i<a;i++){
    char d; cin >> d;
    int e;
    if (d == 'a'){
      cin >> e;
      for (int j=0;j<vec[i-1].size();j++){
        vec[i].push_back(vec[i-1][j]);
      }

      vec[i].push_back(e);
      cout << vec[i][vec[i].size()-1]<< endl;
    }

    if (d == 's'){
      for (int j=0;j<vec[i-1].size();j++){
        vec[i].push_back(vec[i-1][j]);
      }
      vec[i].pop_back();
      cout << vec[i][vec[i].size()-1]<< endl;
    }
    if (d == 't'){
      cin >> e;
      for (int j=0;j<vec[e-2].size();j++){
        vec[i].push_back(vec[e-2][j]);
      }
      cout << vec[i][vec[i].size()-1]<< endl;
    }
  }
}
