#include <iostream>
#include <algorithm>

using namespace std;
#define pp pair<int,int>
pp pos[100001],pos2[100001];
int ans = 0,ans2 = 0;
int n;
void circle(){
  for (int i=0;i<n;i++){
    if (pos[i].first>pos[i].second){
      pos[(i+1)%n].first+=pos[i].first-pos[i].second;
      ans += pos[i].first-pos[i].second;
      pos[i].first = pos[i].second;
    }
  }

}
int main(){
  cin >> n;
  for (int i=0;i<n;i++) {cin >> pos[i].first >> pos[i].second; pos2[i] = pos[i];}
  circle();circle();
  cout << min(ans,ans2);
}
