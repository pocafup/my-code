#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

double distance(pair<int,int> aa, pair<int,int> bb){
  return sqrt(pow((aa.first-bb.first),2)+pow((aa.second-bb.second),2));
}

pair<int,int> pos[10001];
bool visited[10001];
vector<pair<int,int> > vec[10001];
int main(){
  queue<pair<pair<int,int>,int> > q;
  int a,b; cin >> a  >> b;
  for (int i=0;i<b;i++){
    cin >> pos[i].first >> pos[i].second;
    if (pos[i].second<=1000){
      q.push(make_pair(make_pair(pos[i].first,pos[i].second),1));
      visited[i] = true;
    }
  }
  //sort(pos,pos+b);
  int begin = 0;
  int end = 1;
  // for (int i=0;i<b;i++){
  //   for (int j=i+1;j<b;j++){
  //     if (i!=j && distance(pos[i],pos[j])<=1000){
  //       vec[i].push_back(pos[j]);
  //       vec[j].push_back(pos[i]);
  //     }
  //   }
  // }
  int ans = 0;
  // cout << distance(make_pair(600,800),make_pair(100,1300)) << endl;
  while(!q.empty()){

    int qf = q.front().first.first;
    int qs = q.front().first.second;
    int point = q.front().second;
    if (abs(a-qs)<=1000 || abs(a-qf)<=1000){
      ans = point;
      break;
    }

    for (int i=0;i<b;i++){
      if (pos[i].first!=qf || pos[i].second!=qs){
        if (distance(q.front().first,pos[i])<=1000 && !visited[i]){
            visited[i] = true;
          q.push(make_pair(pos[i],point+1));
        }
      }
    }
    q.pop();
  }
  cout << ans;
}
