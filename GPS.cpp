#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool sorted(pair<pair<int,int>, pair<int,int> > aa, pair<pair<int,int>, pair<int,int> > bb) {return aa.first.first != bb.first.first ? aa.first.first < bb.first.first : aa.first.second < bb.first.second;}

int main(){
  int n,m; cin >> n >> m;
  pair<int,int> graph[n][n];
  pair<pair<int,int>, pair<int,int> > keep[m];
  for (int i=0;i<m;i++){
    cin >> keep[i].first.first >> keep[i].first.second >> keep[i].second.first >> keep[i].second.second;
  }
  sort(keep,keep+m,sorted);
  for (int i=0;i<m;i++){
    cout << keep[i].first.first << " " <<keep[i].first.second << " " << keep[i].second.first << " " << keep[i].second.second <<endl;
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){

    }
  }
}
