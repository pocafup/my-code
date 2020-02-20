#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
bool sorted (int a, int b){
  return a>b;
}
int length(int a){
  int length = 1;
  while(a>=10) {a/=10;length++;}
  return length;
}
int main(){
  int a; cin >> a;

  for (int i=1;i<=a;i++){
    int ti; cin >> ti;
    vector<int> vec;
    for (int j=0;j<ti;j++){
      string b;
      int c;

      getline(cin,b,' ');
      cin >> c;
      int now = c;
      vec.push_back(now);
    }
    vec.erase(vec.begin());
    int ans = vec[(int)vec.size()-1];
    vec.pop_back();
    sort(vec.begin(),vec.end(),sorted);
    if (vec.size()) ans = max(ans,vec[0]);
    cout << "Assembly #" << i << ": " <<  ans << endl;
  }
}
