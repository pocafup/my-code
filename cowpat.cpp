#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;
int n;
map<string,int> mp;
int res[5];
int ans = 0;
void dfs(int pos, string now, int times){
  now+='?';
  now += res[pos]+65;
  // for (int i=0;i<now.length();i++) cout << now[i];
  // cout << endl;
  // map<string,int>::iterator it;
  // it = mp.find(now);
  ans+= (times&1) ? mp[now]++: -mp[now]++;
  // else mp[now] = 1;
  for (int i=pos+1;i<5;i++) dfs(i,now,times+1);
}
int main(){
  ifstream cin ("desktop/abcac.in");
  cin >> n;
  for (int i=0;i<n;i++){
    for (int j=0;j<5;j++) cin >> res[j];
    sort(res,res+5);
    string s = "";
    for (int j=0;j<5;j++) dfs(j,s,0);
  }
  cout << (n*(n-1))/2-ans;
}
