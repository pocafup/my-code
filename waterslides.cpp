#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dfs(int x,int y){
  for (x)
}
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  vector<pair<pair<int,int>,int> > p;
  for (int i=0;i<b;i++){
    int d,e,f;
    cin >> d >> e >> f;
    pair<pair<int,int>,int>s;
    s.first.first = d;
    s.first.second = e;
    s.second = f;
    p.push_back(s);
  }
  sort(p.begin(),p.end());

  for (int i=0;i<p.size();i++){
    cout << p[i].first.first <<" " << p[i].first.second <<" " <<p[i].second << endl;
  }
}
