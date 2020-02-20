#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int,int> > d[50000];

int dfs(int q,int r,int zz,int k){
  if (q==zz){
    return 0;
  }else{
    int maxi = 0;
    int mini = 1000000000;
    for (int i=0;i<d[q].size();i++){
    //  maxi = max(maxi,dfs(d[q][i].first,0,zz,k)+d[q][i].second);
      if (k>=0){
      mini = min(mini,dfs(d[q][i].first,0,zz,k-1)+d[q][i].second);
      }
    }
    return mini;
  }
}


int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int f=0,g=0,h=0;
  for (int i=0;i<b;i++){
    cin >> f >> g >> h;
    d[f].push_back(make_pair(g,h));
  }
  int cc = dfs(1,0,a,c);)
  cout << cc;
}
